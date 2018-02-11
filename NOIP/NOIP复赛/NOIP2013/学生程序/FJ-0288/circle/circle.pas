program circle;
var n,m,k,x,i,j:longint;tot:qword;
begin
 assign(input, 'circle.in');assign(output,'circle.out');
 reset(input);rewrite(output);
 readln(n,m,k,x);
 tot:=trunc(exp(k*ln(10)));
 for i:=1 to tot do
  x:=(x+m)mod n;
 writeln(x);
 close(input);close(output);
end.
