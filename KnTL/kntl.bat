@echo off

:: Compile command
set COMPILE=g++ -std=c++11

:: Precompile section
if exist "%~dp0converter.exe" goto ConverterCompiled
echo Compiling "%~dp0converter.cpp"
%COMPILE% -o "%~dp0converter" "%~dp0converter.cpp"
echo Done
:ConverterCompiled
if exist "%~dp0CDBG.h.gch" goto HeaderPrecompiled
echo Precompiling "%~dp0CDBG.h"
%COMPILE% "%~dp0CDBG.h"
echo Done
:HeaderPrecompiled
if exist "%~dp0paster.exe" goto PasterCompiled
echo Compiling "%~dp0paster.cpp"
%COMPILE% -o "%~dp0paster" "%~dp0paster.cpp"
echo Done
:PasterCompiled

:: Command line argument check and file name initialization
set argC=0
for %%x in (%*) do Set /A argC+=1
if %argC%==1 goto ArgC_Correct
echo Please provide cpp file...
goto END
:ArgC_Correct
set cpp=%1
set cpp=%cpp:"=%
set exe="%cpp:~0,-4%.exe"
del %exe%

:: Compiling section
:RECOMPILE
set compiled=1
set tmpcpp="%cd%\.cpp"
"%~dp0converter.exe" "%cpp%" %tmpcpp%
if %errorlevel% neq 0 goto END
%COMPILE% -I"%~dp0\" -o %exe% %tmpcpp%
if %errorlevel% equ 0 goto RUN
set compiled=0
del %tmpcpp%
pause > nul

:: Command section
:RUN
cls
set input=2
if %compiled% equ 1 goto SOURCECOMPILED
if %compiled% equ 0 goto SOURCENOTCOMPILED

:SOURCECOMPILED
set /p input="[92m%cpp%[0m: [93m1[0m:exe [93m2[0m:IN [93m3[0m:IN+OUT [93mp[0maste [93mc[0mompile [93mq[0muit[92m: [0m"
if "%input%"=="1" goto LAUNCH
if "%input%"=="2" goto LAUNCH
if "%input%"=="3" goto LAUNCH
goto RUN2
:SOURCENOTCOMPILED
set /p input="[92m%cpp%[0m: 1:exe 2:IN 3:IN+OUT [93mp[0maste [93mc[0mompile [93mq[0muit[92m: [0m"

:RUN2
if "%input%"=="q" goto END
if "%input%"=="c" goto RECOMPILE
if "%input%"=="p" goto PASTE
if "%input%"=="P" goto PASTEnGO
goto RUN

:LAUNCH
start cmd /s /c ""%~dp0kntl2.bat" %exe% "%input%""
goto RUN

:PASTE
"%~dp0paster%" > IN
if %errorlevel% neq 0 goto END
goto RUN

:PASTEnGO
"%~dp0paster%" > IN
if %errorlevel% neq 0 goto END
set input=2
goto LAUNCH

:END
