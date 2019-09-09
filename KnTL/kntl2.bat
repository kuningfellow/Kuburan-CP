@echo off

if %2=="1" goto CASE1
if %2=="2" goto CASE2
if %2=="3" goto CASE3
goto END

:CASE1
  cls
  set sT=%TIME%
  echo [%1]
  %1
  echo ============================================================
  echo %1
  set progReturn=%errorlevel%
  goto CONTINUE
:CASE2
  cls
  set sT=%TIME%
  %1 < IN
  echo ============================================================
  echo %1 ^< IN
  set progReturn=%errorlevel%
  goto CONTINUE
:CASE3
  cls
  set sT=%TIME%
  %1 < IN > OUT
  echo ============================================================
  echo %1 ^< IN ^> OUT
  set progReturn=%errorlevel%
  goto CONTINUE
:CONTINUE

set eT=%TIME%

set /a S=0
set sT_h=%sT:~0,2%
set /a S += %sT_h% * 360000
set sT_m=%sT:~3,1%
set /a S += %sT_m% * 60000
set sT_m=%sT:~4,1%
set /a S += %sT_m% * 6000
set sT_s=%sT:~6,1%
set /a S += %sT_s% * 1000
set sT_s=%sT:~7,1%
set /a S += %sT_s% * 100
set sT_t=%sT:~9,1%
set /a S += %sT_t% * 10
set sT_t=%sT:~10,1%
set /a S += %sT_t%

set /a E=0
set eT_h=%eT:~0,2%
set /a E += %eT_h% * 360000
set eT_m=%eT:~3,1%
set /a E += %eT_m% * 60000
set eT_m=%eT:~4,1%
set /a E += %eT_m% * 6000
set eT_s=%eT:~6,1%
set /a E += %eT_s% * 1000
set eT_s=%eT:~7,1%
set /a E += %eT_s% * 100
set eT_t=%eT:~9,1%
set /a E += %eT_t% * 10
set eT_t=%eT:~10,1%
set /a E += %eT_t%

set /a dif = %E% - %S%

set /a dT_h = dif / 360000
set /a dif -= %dT_h% * 360000
set /a dT_m = dif / 6000
set /a dif -= %dT_m% * 6000
set /a dT_s = dif / 100
set /a dif -= %dT_s% * 100

echo Return code: %progReturn%
echo Execution time: %dT_h%:%dT_m%:%dT_s%.%dif%
echo ============================================================
pause > nul

:END
