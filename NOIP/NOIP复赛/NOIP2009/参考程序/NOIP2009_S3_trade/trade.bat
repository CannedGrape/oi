@echo off
if "%1"=="" goto loop
copy trade%1.in trade.in >nul
echo Problem Test
echo Data %1
time<enter
trade.exe
time<enter
fc trade.out trade%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del trade.in
del trade.out