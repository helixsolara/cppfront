# Builds the module regression tests together with MSVC and runs the result.
#
# run-tests.sh only transpiles the *-module-* tests, because each one is a unit
# of a multi-file module (or a program importing it) and can't be compiled
# alone. This script compiles their generated code from test-results in
# dependency order, links the 'shapes' module with its consumer, runs it and
# compares the output with test-results/pure2-module-consumer.cpp.execution.
# It also compiles mixed-module-global-fragment.cpp on its own, and builds the
# 'greeter' module (pure2-module-private-fragment, whose function bodies are in
# its private module fragment) with its consumer and checks that program's
# output. Object and .ifc files go to -BuildDir, outside the repo.
#
# Run it from a Developer PowerShell (cl.exe and link.exe on PATH), after
# run-tests.sh has regenerated test-results:
#   powershell -NoProfile -ExecutionPolicy Bypass -File regression-tests\build-module-tests.ps1

param(
    [string] $BuildDir = (Join-Path ([IO.Path]::GetTempPath()) 'cppfront-module-tests')
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$resultsDir = Join-Path $PSScriptRoot 'test-results'
$includeDir = Join-Path (Split-Path $PSScriptRoot -Parent) 'include'

# The units of module 'shapes' in dependency order, with the MSVC flag that
# says what kind of module unit each one is
$shapesUnits = @(
    @{ Name = 'pure2-module-partition';          Kind = '/interface' },
    @{ Name = 'pure2-module-internal-partition'; Kind = '/internalPartition' },
    @{ Name = 'pure2-module-interface';          Kind = '/interface' },
    @{ Name = 'pure2-module-implementation';     Kind = '' },
    @{ Name = 'pure2-module-consumer';           Kind = '' }
)

function Invoke-Compile {
    param(
        [Parameter(Mandatory = $true)] [string] $Name,
        [string] $Kind
    )
    $source = Join-Path $resultsDir "$Name.cpp"
    $arguments = @('/nologo', '/std:c++latest', '/EHsc', '/c', '/I', $includeDir, '/ifcSearchDir', '.')
    if ($Kind) {
        $arguments += $Kind
    }
    & cl.exe @arguments $source
    if ($LASTEXITCODE) {
        throw "Compiling $source failed"
    }
}

function Test-ShapesOutput {
    $expected = [IO.File]::ReadAllText((Join-Path $resultsDir 'pure2-module-consumer.cpp.execution')).Replace("`r`n", "`n")
    $actual = ((& .\shapes.exe) -join "`n") + "`n"
    if ($LASTEXITCODE) {
        throw "shapes.exe exited with $LASTEXITCODE"
    }
    if ($actual -ne $expected) {
        throw "shapes.exe output differs from pure2-module-consumer.cpp.execution:`n$actual"
    }
}

New-Item -ItemType Directory -Force -Path $BuildDir | Out-Null
Push-Location -LiteralPath $BuildDir
try {
    foreach ($unit in $shapesUnits) {
        Invoke-Compile -Name $unit.Name -Kind $unit.Kind
    }
    $objects = $shapesUnits | ForEach-Object { "$($_.Name).obj" }
    & link.exe /nologo /out:shapes.exe @objects
    if ($LASTEXITCODE) {
        throw 'Linking shapes.exe failed'
    }
    Test-ShapesOutput

    Invoke-Compile -Name 'mixed-module-global-fragment' -Kind '/interface'

    #  Module 'greeter', whose function bodies are in its private module
    #  fragment (module :private;), and a program importing it
    Invoke-Compile -Name 'pure2-module-private-fragment' -Kind '/interface'
    Invoke-Compile -Name 'pure2-module-private-fragment-consumer'
    & link.exe /nologo /out:private-fragment.exe pure2-module-private-fragment.obj pure2-module-private-fragment-consumer.obj
    if ($LASTEXITCODE) {
        throw 'Linking private-fragment.exe failed'
    }
    $expected = [IO.File]::ReadAllText((Join-Path $resultsDir 'pure2-module-private-fragment-consumer.cpp.execution')).Replace("`r`n", "`n")
    $actual = ((& .\private-fragment.exe) -join "`n") + "`n"
    if ($actual -ne $expected) {
        throw "private-fragment.exe output differs from pure2-module-private-fragment-consumer.cpp.execution:`n$actual"
    }

    Write-Output 'Module tests built and ran as expected'
}
finally {
    Pop-Location
}
