program p01_2(input,output);{最大公约数与最小公倍数问题}
var x0,y0,i,p,q,pq,sum:longint;

function lcd(x,y:longint):longint;
var z:longint;
begin
    z:=y mod x;
    while z<>0 do
    begin y:=x;x:=z;z:=y mod x ;end;
    lcd:=x;
end;

begin
     assign(input,'gygb.in');
     reset(input);
     readln(x0,y0);
     close(input);
     if (y0 div x0)*x0<>y0 then sum:=0
       else
         begin
             sum:=2;
             for i:=2 to (y0 div x0 -1) do
                 begin p:=i*x0;
                       q:=y0 div i;
                       if (q<=p)  then break;
                       pq:=lcd(p,q);
                       if (pq=x0) and (p div pq * q=y0) then sum:=sum+2

                 end;
         end;
     assign(output,'gygb.out');
     rewrite(output);
     writeln(sum);
     close(output);
end.

