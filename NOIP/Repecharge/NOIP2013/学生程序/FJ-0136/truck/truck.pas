program truck;
var n,m,q,i,j:longint;
a,b,c,d,e:array[1..100000]of longint;
f1,f2:text;














procedure try(x,y:longint);
var i,j,z,s,p:longint;
t:array[1..100000]of boolean;
begin
p:=x;
if p=y then
begin
writeln(f2,z);
close(f2);
halt;
end;
z:=maxlongint;
for i:=1 to n-1 do
if (b[i]=p)and(t[c[i]]=false)then
begin
t[p]:=true;
if a[i]<z then z:=a[i];
p:=c[i];
try(p,y);
z:=a[i];
p:=b[i];
end;
writeln(f2,'-1');
close(f2);
end;













begin
assign(f1,'truck.in');
reset(f1);
assign(f2,'truck.out');
rewrite(f2);
read(f1,n,m);
for i:=1 to m do
read(f1,b[i],c[i],a[i]);
read(f1,q);
for i:=1 to q do
read(f1,d[i],e[i]);
for i:=1 to q do
try(d[i],c[i]);
end.

