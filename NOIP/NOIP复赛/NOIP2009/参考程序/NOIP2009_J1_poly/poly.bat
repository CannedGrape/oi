@echo off
if "%1"=="" goto loop
copy poly%1.in poly.in >nul
echo Problem Test
echo Data %1
time<enter
poly.exe
time<enter
fc poly.out poly%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del poly.in
del poly.out