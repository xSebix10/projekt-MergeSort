@echo off
echo --- BUDOWANIE TESTOW ---
cmake --build build

if %ERRORLEVEL% NEQ 0 (
    echo [BLAD] Kompilacja nie powiodla sie!
    pause
    exit /b
)

echo.
echo --- URUCHAMIANIE TESTOW ---
echo.
build\MergeSortTests.exe

echo.
pause