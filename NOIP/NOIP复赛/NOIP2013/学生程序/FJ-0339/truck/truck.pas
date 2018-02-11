program truck;
uses math;
var
 f,a:array[0..1000,0..1000]of longint;
 father:array[1..1000]of longint;
 flag:array[1..1000]of boolean;
 n,m,x,y,z,q,i,j:longint;

function get(x:longint):longint;
begin
 if father[x]=x then exit(x)
 else get:=get(father[x]);
end;

procedure union(x,y:longint);
var fx,fy:longint;
begin
 fx:=get(x);
 fy:=get(y);
 if fx<>fy then father[fy]:=fx;
end;

procedure net(i:longint);
var j,k:longint;
begin
 for j:=1 to a[i,0] do
  for k:=1 to a[a[i,j],0] do
   if min(f[i,a[i,j]],f[a[i,j],a[a[i,j],k]])>f[i,a[a[i,j],k]] then
    f[i,a[a[i,j],k]]:=min(f[i,a[i,j]],f[a[i,j],a[a[i,j],k]]);
end;

begin
 assign(input,'truck.in'); reset(input);
 assign(output,'truck.out'); rewrite(output);
 readln(n,m);
 for i:=1 to n do
  for j:=1 to n do f[i,j]:=0;
 for i:=1 to n do
 begin
  father[i]:=i;
  flag[i]:=true;
 end;
 for i:=1 to m do
 begin
  readln(x,y,z);
  f[x,y]:=z;
  f[y,x]:=z;
  union(x,y);
  a[x,0]:=a[x,0]+1;
  a[x,a[x,0]]:=y;
  a[y,0]:=a[y,0]+1;
  a[y,a[y,0]]:=x;
 end;
 for i:=1 to n do
  if flag[get(i)] then net(i);
 readln(q);
 for i:=1 to q do
 begin
  readln(x,y);
  if f[x,y]>0 then writeln(f[x,y])
  else writeln('-1');
 end;
 close(input); close(output);
end.
