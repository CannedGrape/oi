uses math;
var n,i,j:longint; u,d,a:array[1..20000]of longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do begin read(a[i]); u[i]:=1; d[i]:=1; end;
for i:=2 to n do
 for j:=1 to i-1 do
  if(a[j]<a[i])and(u[j]+1>d[i])then d[i]:=u[j]+1
  else if(a[j]>a[i])and(d[j]+1>u[i])then u[i]:=d[j]+1;
writeln(max(maxvalue(u),maxvalue(d)));
close(input);
close(output);
end.
