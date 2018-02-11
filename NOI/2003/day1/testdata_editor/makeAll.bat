@echo off
if "%1"=="" goto all
move editor%1.in editor.in
ans.exe
move editor.in editor%1.in
move editor.out editor%1.out

goto end

:all
del *.in
del *.out
gen
for %%d in (1,2,3,4,5,6,7,8,9,0) do call makeAll.bat %%d
pause


:end
