@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 2. Оголошення та ініціалізація масивів.
rem  До показу спрогнозуйте: що лежить у b, g і u?
rem ============================================================
cd /d "%~dp0"
set "DBG=%~dp0..\x64\Debug\Demo2_decl.exe"
set "REL=%~dp0..\x64\Release\Demo2_decl.exe"
if not exist "%DBG%" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )

echo === Debug ===
echo ^> Demo2_decl.exe
"%DBG%"
echo.
echo   b - решта нулі; g - глобальний, нулі; u - сміття зі стека.
pause
if not exist "%REL%" ( echo [!] Для порівняння зберіть ще й Release. & exit /b 0 )
echo.
echo === Release ===
echo ^> Demo2_decl.exe
"%REL%"
echo.
echo   u - інше сміття: неініціалізований локальний масив непередбачуваний.
pause