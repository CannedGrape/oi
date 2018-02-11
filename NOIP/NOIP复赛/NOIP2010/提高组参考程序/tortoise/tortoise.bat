@echo off
if "%1"=="" goto loop
copy tortoise%1.in tortoise.in >nul
echo Problem Test
echo Data %1
time<enter
tortoise.exe
time<enter
fc tortoise.out tortoise%1.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
del tortoise.in
del tortoise.out
