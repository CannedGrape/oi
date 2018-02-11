program truck;
var
n,q,x,y,t,k,i,j,m:longint;
a:array[1..10000,0..50000] of longint;
b:array[1..10000,1..10000] of integer;
w:array[1..10000,1..10000] of longint;
f:array[1..50000] of longint;
f1,f2:text;
function max(a,b:longint):longint;
begin
if a>b then exit(a)
else exit(b);
end;
begin
assign(f1,'truck.in');reset(f1);
assign(f2,'truck.out');rewrite(f2);
readln(n,m);
for i:=1 to m do
begin
read(x,y,w[x,y]);
inc(a[x,0]);
a[x,a[x,0]]:=y;
inc(a[y,0]);
a[y,a[y,0]]:=x;
w[y,x]:=w[x,y];
end;
readln(q);
for i:=1 to q do
for j:=1 to q do b[i,j]:=0;
for i:=1 to q do
begin
read(x,y);
b[i,x]:=y;
end;
for i:=1 to q do
begin
fillchar(f,sizeof(f),0);
for j:=1 to n do
if b[i,j]<>0 then
for t:=j to b[i,j] do
if a[j,0]=1 then f[t]:=f[t]+w[t,a[t,1]]
else
for k:=1 to a[t,0] do
f[t]:=max(f[t],f[t]+w[t,a[t,k]]);
writeln(f[b[i,j]]);
end;
close(f1);close(f2);
end.
