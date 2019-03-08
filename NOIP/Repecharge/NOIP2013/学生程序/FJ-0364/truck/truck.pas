var i,j,n,x,y,m,q,k:longint;  mm,z,max:longint;
tu:array[1..10000,1..10000]of longint;
f,t,ans:array[1..30000]of integer;
inf,ouf:text;
procedure init;
begin
assign(inf,'truck.in');reset(inf);
assign(ouf,'truck.out');rewrite(ouf);
read(inf,n,m);
for i:=1 to m do
begin
read(inf,x,y,z);if x>mm then mm:=x;if y>mm then mm:=y;
tu[x,y]:=z;tu[y,x]:=z;end;
read(inf,q);
for i:=1 to q do
read(inf,f[i],t[i]);
end;

procedure try(i,l,r:longint);
begin
if (l<>f[i])and(r=t[i]) then exit;
max:=maxlongint;
for k:=l+1 to n do
for j:=k+1 to n do
if tu[k,j]<>0 then begin if tu[k,j]<max then
begin max:=tu[k,j];if max>ans[i] then ans[i]:=max;end;
try(i,k,j);
end;
end;

begin
init;
for i:=1 to q do
begin
if tu[f[i],t[i]]<>0 then ans[i]:=tu[f[i],t[i]];
try(i,f[i],f[i]+1);
end;


for j:=1 to q do
if (f[j]>mm)or(t[j]>mm) then ans[j]:=-1;

for i:=1 to q do
writeln(ouf,ans[i]);
close(inf);close(ouf);

end.
