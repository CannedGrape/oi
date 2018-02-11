@echo off
if "%1"=="" goto loop
copy ball.00%1 ball.in >nul
echo Problem Test
echo Data %1
ball
type ball.out
@echo fc ball.out ball%1.out
del ball.in
del ball.out
pause
goto end
:loop
for %%i in (1 2 3 4 5) do call %0 %%i
:end
