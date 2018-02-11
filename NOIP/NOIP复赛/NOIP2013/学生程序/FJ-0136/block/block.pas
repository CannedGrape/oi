program block;
var n,m,i,j:longint;
a:array[0..10000]of longint;
f1,f2:text;
begin
assign(f1,'block.in');
reset(f1);
assign(f2,'block.out');
rewrite(f2);
j:=-maxlongint;
read(f1,n);
for i:=1 to n do
read(f1,a[i]);
for i:=1 to n do
if a[i]>=j then j:=a[i];
m:=j;
for i:=1 to n do
if a[i-1]=1 then m:=m+a[i]-1;
writeln(f2,m);
close(f2);
end.