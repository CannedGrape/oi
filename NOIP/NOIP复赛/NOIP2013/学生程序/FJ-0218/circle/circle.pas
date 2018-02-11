//Veni, vedi, vici.
Program circle;
uses math;
var
guys,gap,t10e,guy,ans:longint;
dig,rt10e:longint;
power:longint;
BEGIN
assign(input,'circle.in');
assign(output,'circle.out');
reset(input); rewrite(output);

read(guys,gap,t10e,guy);

if (gap > guys) then gap:=gap mod guys;
//find the least power which is greater than guys;
//Use that instead of t10e;
//1,000,000 for the greatest.

dig := trunc(ln(guys)/ln(10));
rt10e := dig+1;
if (t10e > rt10e)
    then t10e := rt10e;
        power:= 1 ;
        while (t10e > 0) do begin
            power := power*10;
            t10e:=t10e -1;
        end;
            power := power div 10;
            power := power * gap;
        //每次移动的格子数量
        //writeln('got power',power);
        power := power mod guys;
        //其中guys次会让你走到一样的地方，故mod
        //然后走呗
        //writeln('really adding',power);
        ans := power + guy;
        ans := ans mod guys;

    writeln(ans);
    
    close(input);
    close(output);
END.
