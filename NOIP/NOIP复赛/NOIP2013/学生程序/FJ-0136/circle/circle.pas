program circle;
var n,m,k,x,i,j,y,z:longint;
f1,f2:text;
a,b:array[0..100000]of longint;
begin
assign(f1,'circle.in');
reset(f1);
assign(f2,'circle.out');
rewrite(f2);
read(f1,n,m,k,x);
for i:=0 to n-1 do
a[i]:=i;
y:=1;
for i:=1 to k do
y:=y*10;
for j:=1 to y do
begin
z:=0;
for i:=0 to n-1 do
begin
if a[i]<n-1-m then a[i]:=m+a[i];
if a[i]>=n-1-m then
begin
a[i]:=z;
z:=z+1;
end;
end;
end;
for i:=0 to n-1 do
if a[i]=x then
begin
writeln(f2,i);
close(f2);
halt;
end;
end.
