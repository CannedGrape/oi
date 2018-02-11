program flower;
var n,m,i,j:longint;
a:array[0..100000]of longint;
b:array[1..100000]of boolean;
f1,f2:text;
begin
assign(f1,'flower.in');
reset(f1);
assign(f2,'flower.out');
rewrite(f2);
read(f1,n);
for i:=2 to n do
read(f1,a[i]);
b[i]:= true;
for i:=2 to (n div 2) do
begin
if (a[2*i]>a[2*i+1]) and (a[2*i]>a[2*i-1]) or (a[2*i]<a[2*i+1]) and (a[2*i]<a[2*i-1]) then
b[i]:=true else b[i]:=false;
end;
for i:=1 to n do
if b[i]=true then j:=j+1;
writeln(f2,j);
close(f2);
end.
