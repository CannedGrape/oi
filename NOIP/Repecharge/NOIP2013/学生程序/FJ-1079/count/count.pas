program count;
var x,a,b,j,f,i:integer;
    n,z:int64;
begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
 readln(n,x);
 z:=0;
 a:=0;
 b:=0;
 for i:=1 to n do
 begin
  a:=i mod 10;
  b:=i div 10;
  for j:=1 to a do
  begin
   if a=x
   then
   z:=z+j;
  end;
  for f:=1 to b do
  begin
   if b=x
   then
   z:=z+f;
  end;
 end;
 writeln(z);
 close(input);
 close(output);
 end.


