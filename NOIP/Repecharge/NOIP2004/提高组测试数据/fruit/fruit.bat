@echo off
if "%1"=="" goto loop
copy fruit%1.in fruit.in >nul
echo Problem Test
echo Data %1
time<enter
fruit.exe
time<enter
fc fruit.out fruit%1.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del fruit.in
del fruit.out