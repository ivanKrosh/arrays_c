@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 6. Двовимірний масив у пам'яті.
rem  До показу спрогнозуйте: яка адреса в m[1][0], якщо m[0][3] - зсув 12?
rem ============================================================
cd /d "%~dp0"
set "EXE="
if exist "%~dp0..\x64\Release\Demo6_matrix.exe" set "EXE=%~dp0..\x64\Release\Demo6_matrix.exe"
if exist "%~dp0..\x64\Debug\Demo6_matrix.exe" set "EXE=%~dp0..\x64\Debug\Demo6_matrix.exe"
if not defined EXE ( echo [!] Demo6_matrix.exe не знайдено. Зберіть рішення: Build - Build Solution. & exit /b 1 )

echo ^> Demo6_matrix.exe
echo.
"%EXE%"
echo.
echo   Рядок за рядком, без проміжків: за m[0][3] одразу іде m[1][0].
pause