# #line:
#  - This preprocessor directive is used generally when user don't want any error in cpp but it should point to the another file which is in other language through which cpp file is written.
#  - i.e By using this directive, the error will not point the cpp location line number but the line from actual code that is written in another language through this cpp file code is written and executed.

import os, subprocess, time

# Write a cpp file which will point to original file
with open("example.cpp", "w") as fptr:
  fptr.write('#line 1 "config.txt"\n')
  fptr.write('int radius = 1;\n')
  fptr.write('#line 2 "config.txt"\n')
  fptr.write('int radius1 = "abc";\n')
  
# Write a batch command file which will execute above generated cpp file
with open("my_batch.bat", "w") as fptr:
  fptr.write('@echo off\n')
  fptr.write('set SRC=%1\n')
  fptr.write('g++ "%SRC%" -o program.exe\n')
  fptr.write('if %ERRORLEVEL% neq 0 (\n')
  fptr.write('    echo Compilation failed.\n')
  fptr.write('    exit /b 1\n')
  fptr.write(')\n')
  fptr.write('echo Compilation successful.\n')

time.sleep(2)

subprocess.call(["my_batch.bat", "example.cpp"])
