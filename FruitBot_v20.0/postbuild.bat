@echo off
setlocal

:: Set the source path for the .elf file (adjust the path if necessary)
set "SOURCE_PATH=C:\Users\88691\AppData\Local\Temp\arduino\sketches\F610EC214AF4AEAFDF804FD0348F4D99\FruitBot.ino.elf"

:: Set the destination folder (where the .ino file is located)
set "DEST_FOLDER=F:\PHD\Arduino_Projects\FruitBot\FruitBot_v20.0"

:: Path to avr-objcopy tool (adjust the version if necessary)
set "AVR_OBJCOPY=C:\Users\88691\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7\bin\avr-objcopy.exe"

:: Copy the .elf file to the destination folder
if exist "%SOURCE_PATH%" (
    copy "%SOURCE_PATH%" "%DEST_FOLDER%\FruitBot.ino.elf"
    echo .elf file copied to %DEST_FOLDER%
    
    :: Convert .elf to .bin using the full path to avr-objcopy
    "%AVR_OBJCOPY%" -O binary "%DEST_FOLDER%\FruitBot.ino.elf" "%DEST_FOLDER%\FruitBot.ino.bin"
    echo .bin file generated at %DEST_FOLDER%
    
    :: Convert .elf to .hex using the full path to avr-objcopy
    "%AVR_OBJCOPY%" -O ihex "%DEST_FOLDER%\FruitBot.ino.elf" "%DEST_FOLDER%\FruitBot.ino.hex"
    echo .hex file generated at %DEST_FOLDER%
) else (
    echo File not found: %SOURCE_PATH%
)

endlocal
