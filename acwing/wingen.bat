echo "wingen.bat [filename, filename.cpp]"

set basename=%1
echo basename="%basename%"
set filename=%basename%.cpp

@REM if not exist %filename% (
if not exist %filename% (
    copy main.cpp %filename%
    echo %filename% created!
) else (
    echo %filename% exists!
)

python3 clean.py

