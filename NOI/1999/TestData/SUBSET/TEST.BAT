@echo off
if "%1"=="" goto loop
copy subset.00%1 subset.in >nul
echo Problem Test
echo Data %1
subset
echo fc subset.out subset%1.out
type subset.out
pause
del subset.in
del subset.out
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
