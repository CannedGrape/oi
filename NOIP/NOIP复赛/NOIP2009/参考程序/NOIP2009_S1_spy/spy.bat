@echo off
if "%1"=="" goto loop
copy spy%1.in spy.in >nul
echo Problem Test
echo Data %1
time<enter
spy.exe
time<enter
fc spy.out spy%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del spy.in
del spy.out