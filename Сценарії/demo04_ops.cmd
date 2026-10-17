@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 4. Обробка одновимірного масиву.
rem  Пошук: спершу ключ, що є в масиві (94), потім - якого немає (42).
rem ============================================================
cd /d "%~dp0"
set "EXE="
if exist "%~dp0..\x64\Release\Demo4_ops.exe" set "EXE=%~dp0..\x64\Release\Demo4_ops.exe"
if exist "%~dp0..\x64\Debug\Demo4_ops.exe" set "EXE=%~dp0..\x64\Debug\Demo4_ops.exe"
if not defined EXE ( echo [!] Demo4_ops.exe не знайдено. Зберіть рішення: Build - Build Solution. & exit /b 1 )

echo ^> Demo4_ops.exe        key = 94
echo.
echo 94| "%EXE%"
echo.
pause
echo ^> Demo4_ops.exe        key = 42
echo.
echo 42| "%EXE%"
echo.
echo   Після циклу пошуку pos ^< n - знайдено, pos == n - ні.
pause