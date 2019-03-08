var
n,i,t1,j:longint;
a,h,t,f:array[0..100000] of longint;
begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);   t1:=0;
for i:=1 to n do

  for j:=i to n do
  if a[j]>a[i] then inc(h[i]) else
  if a[j]<a[i] then inc(t[i]);

for i:=1 to n do
begin
  f[i]:=f[i]+h[i]-t[i];
end;
for i:=1 to n do
if t1<f[i] then t1:=f[i];
writeln(t1);
close(input);
close(output);
end.