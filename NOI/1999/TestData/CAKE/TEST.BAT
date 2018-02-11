@echo off
if "%1"=="" goto loop
copy cake.00%1 cake.in >nul
echo Problem Test
echo Data %1
cake
type cake.out
@echo fc cake.out cake%1.out
del cake.in
del cake.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
