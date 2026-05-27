$ErrorActionPreference = 'Stop'

function Assert-Expr {
    param(
        [int]$Expected,
        [string]$Input
    )

    & .\MyC.exe $Input | Set-Content -NoNewline tmp.s

    & clang -o tmp.exe tmp.s
    & .\tmp.exe
    $Actual = $LASTEXITCODE

    if ($Actual -eq $Expected) {
        Write-Host "$Input => $Actual"
    }
    else {
        Write-Host "$Input => expected $Expected, but got $Actual"
        exit 1
    }
}


Assert-Expr 0   "0"
Assert-Expr 42  "42"
Assert-Expr 21  "5+20-4"
Assert-Expr 41  " 12 + 34 - 5 "
Assert-Expr 47  "5+6*7"
Assert-Expr 15  "5*(9-6)"
Assert-Expr 4   "(3+5)/2"

Write-Host "OK"