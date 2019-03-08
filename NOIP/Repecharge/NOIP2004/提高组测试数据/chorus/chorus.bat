@echo off
if "%1"=="" goto loop
copy chorus%1.in chorus.in >nul
echo Problem Test
echo Data %1
time<enter
chorus.exe
time<enter
fc chorus.out chorus%1.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del chorus.in
del chorus.out