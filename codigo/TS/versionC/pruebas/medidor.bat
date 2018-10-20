@echo off
call :timer start
dir
call :timer
goto :eof

:timer
if /i "%1"=="start" set timer=
for /f "tokens=2-5 delims=:,." %%a in ('echo.^|time^|find /i
"current"') do (
  set hh=%%a
  set /a mm=1%%b-100,ss=1%%c-100,dd=1%%d-100
)
set /a hh=1%hh:~1,2%-100,timer=hh*3600000+mm*60000+ss*1000+dd*10-timer
if /i not "%1"=="start" echo elapsed time = %timer% msec
goto :eof 

:eof
