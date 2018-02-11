@echo off
if "%1"=="" goto loop
copy memory.00%1 memory.in >nul
echo Problem Test
echo Data %1
memory
echo fc memory.out memory%1.out
type memory.out
pause
del memory.in
del memory.out
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
