@echo off
echo --- BUDOWANIE PROJEKTU ---
cmake --build build

if %ERRORLEVEL% NEQ 0 (
    echo [BLAD] Kompilacja nie powiodla sie!
    pause
    exit /b
)

echo.
echo --- URUCHAMIANIE APLIKACJI ---
echo.
build\MergeSortApp.exe

echo.
echo --- KONIEC ---
pause