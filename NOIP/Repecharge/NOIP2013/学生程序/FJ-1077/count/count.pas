program exp1;
var n,i:longint;
x,a:integer;
begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
 readln(n,x);
 i:=0;
 x:=0;
 for i:=i+1 to n do
 begin
  if i mod 10=x then a:=a+1;
  if i div 10=x then a:=a+1;
  if i div 100=x then a:=a+1;
 end.
 close(input);
 writeln(a);
 close(output);
end.
