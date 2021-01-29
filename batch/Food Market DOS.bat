@echo off
title WINDOWS FELING
color b0
:load
echo searching driver......
ping n-127.9.2.1>nul
ping n-127.9.5.1>nul
ping n-127.5.7.1>nul
ping n-127.0.0.1>nul
echo starting windows feling.......
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
 
:login
cls
echo HORAS!
set /p us=username :
set /p pass=password :

:WEL
cls
echo.
ping n-127.0.0.1>nul
echo.
echo.
echo.
echo                             WELCOME TO WINDOWS FELING
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
ping n-127.0.0.1>nul
goto login