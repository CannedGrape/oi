@echo off
if "%1"=="" goto loop
copy sequence.00%1 sequence.in >nul
echo Problem Test
echo Data %1
sequence
@echo fc sequence.out sequence%1.out
type sequence.out
sjudge
pause
del sequence.in
del sequence.out
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
