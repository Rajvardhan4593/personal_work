@echo off
set SRC=%1
g++ "%SRC%" -o program.exe
if %ERRORLEVEL% neq 0 (
    echo Compilation failed.
    exit /b 1
)
echo Compilation successful.
