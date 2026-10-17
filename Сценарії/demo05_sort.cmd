@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 5. Сортування бульбашкою і вибором.
rem  До показу спрогнозуйте: який метод зробить менше обмінів?
rem ============================================================
cd /d "%~dp0"
set "EXE="
if exist "%~dp0..\x64\Release\Demo5_sort.exe" set "EXE=%~dp0..\x64\Release\Demo5_sort.exe"
if exist "%~dp0..\x64\Debug\Demo5_sort.exe" set "EXE=%~dp0..\x64\Debug\Demo5_sort.exe"
if not defined EXE ( echo [!] Demo5_sort.exe не знайдено. Зберіть рішення: Build - Build Solution. & exit /b 1 )

echo ^> Demo5_sort.exe
echo.
"%EXE%"
echo.
echo   Порівнянь в обох методах - порядку n^^2/2. Обмінів у вибору - не більше n - 1.
pause