@echo off
if "%1"=="" goto loop
copy son%1.in son.in >nul
echo Problem Test
echo Data %1
time<enter
son.exe
time<enter
fc son.out son%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del son.in
del son.out