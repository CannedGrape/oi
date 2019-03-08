@echo off
if "%1"=="" goto loop
copy sudoku%1.in sudoku.in >nul
echo Problem Test
echo Data %1
time<enter
sudoku.exe
time<enter
fc sudoku.out sudoku%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end
del sudoku.in
del sudoku.out