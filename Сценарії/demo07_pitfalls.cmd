@echo off
chcp 65001 > nul
rem ============================================================
rem  Демо 7. Помилки роботи з масивами. Жодна не дає попередження /W4.
rem  До показу спрогнозуйте: що надрукує кожен рядок?
rem ============================================================
cd /d "%~dp0"
set "DBG=%~dp0..\x64\Debug\Demo7_pitfalls.exe"
set "REL=%~dp0..\x64\Release\Demo7_pitfalls.exe"
if not exist "%DBG%" ( echo [!] Зберіть рішення в конфігурації Debug. & exit /b 1 )
if not exist "%REL%" ( echo [!] Зберіть рішення в конфігурації Release. & exit /b 1 )

echo === Debug ===
echo ^> Demo7_pitfalls.exe
"%DBG%"
echo.
echo === Release ===
echo ^> Demo7_pitfalls.exe
"%REL%"
echo.
echo   Рядок 1: у Debug limit зіпсовано, у Release - надруковано старе значення.
echo   Запис за межу відбувся в обох випадках.
pause
echo.
echo === Великий масив: static, купа, стек ===
echo ^> Demo7_pitfalls.exe stack
"%REL%" stack
echo.
echo   Код завершення: %errorlevel%   (-1073741571 = 0xC00000FD, переповнення стека)
pause
echo.
echo === Запис за межу локального масиву ===
echo ^> Demo7_pitfalls.exe overrun      Release
"%REL%" overrun
echo   Код завершення: %errorlevel%   - помилки не видно.
echo.
echo ^> Demo7_pitfalls.exe overrun      Debug, /RTC
echo   Очікується вікно Run-Time Check Failure #2. Натисніть Abort або Ignore.
"%DBG%" overrun
pause