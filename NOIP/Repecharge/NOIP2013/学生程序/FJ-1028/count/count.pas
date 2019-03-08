program count;
var m,x:integer;
  i,n:longint;
begin
  assign(input,'count.in');
  assign(output,'count.out');
  reset(input);
  readln(n,x);
  for i:=1 to n do
  begin
    if (i mod 10=x) then m:=m+1;
    if ((i mod 100)-(i mod 10)=x*10) then m:=m+1;
    if ((i mod 1000)-(i mod 100)=x*100) then m:=m+1;
    if ((i mod 10000)-(i mod 1000)=x*1000) then m:=m+1;
    if ((i mod 100000)-(i mod 10000)=x*10000) then m:=m+1;
    if ((i mod 1000000)-(i mod 100000)=x*100000) then m:=m+1;
    if (i div 1000000=x) then m:=m+1;
  end;
  rewrite(output);
  writeln(m);
  close(input);
  close(output);
end.

