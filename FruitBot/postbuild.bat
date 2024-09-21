@echo off
REM Define source and destination directories
set "source=C:\Users\88691\AppData\Local\Temp\arduino\sketches\039E7A1570A3A4494B5D2E7DC308E99B\FruitBot.ino.elf"
set "destination=%~dp0FruitBot.ino.elf"

REM Copy the ELF file from the source to the current .ino directory
if exist "%source%" (
    echo Copying file...
    copy "%source%" "%destination%" /Y
    echo File copied successfully!
) else (
    echo Source file does not exist: %source%
)

pause
