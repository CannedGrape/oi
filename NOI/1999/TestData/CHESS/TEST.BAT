@echo off
if "%1"=="" goto loop
copy chess.00%1 chess.in >nul
echo Problem Test
echo Data %1
chess
echo fc chess.out chess%1.out
type chess.out
pause
del chess.in
del chess.out
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
