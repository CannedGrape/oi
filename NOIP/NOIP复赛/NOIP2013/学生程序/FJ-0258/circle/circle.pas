program circle;
uses math;
var
n,m,k,x,y,i:longint;
g:longint;
  begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);

readln(n,m,k,x);

y:=x;

g:=trunc(power(10,k));

for i:=1 to g do
begin

  y:=y+m;

end;

writeln(y mod n);

close(input);
close(output);
end.
