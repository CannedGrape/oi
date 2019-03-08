@echo off
if "%1"=="" goto loop
copy alpha%1.in alpha.in >nul
echo Problem Test
echo Data %1
time<enter
alpha.exe
time<enter
fc alpha.out alpha%1.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del alpha.in
del alpha.out