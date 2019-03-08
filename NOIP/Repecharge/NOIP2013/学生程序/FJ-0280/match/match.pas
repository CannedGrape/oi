program woprk;
type dota=record
       h,x:longint;
       end;
     dota1=array[0..100001] of dota;
var a,b:dota1;
    f:array[0..100001] of longint;
    i,j,n,m,p,x,y,k,ans:longint;
procedure init;
begin
 assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
procedure sort(var a:dota1;l,r:longint);

procedure kp(l,r:longint);
var i,j,x:longint;t:dota;
begin
 i:=l;j:=r;
 x:=a[(i+j+j)div 3].h;
 repeat
  while a[i].h<x do inc(i);
  while a[j].h>x do dec(j);
  if i<=j then
  begin
   t:=a[i];a[i]:=a[j];a[j]:=t;
   inc(i);dec(j);
  end;
 until i>j;
if i<r then kp(i,r);
if l<j then kp(l,j);
end;
begin
 kp(l,r);
end;

procedure swap(var x,y:longint);
var t:longint;
begin
 t:=x;x:=y;y:=t;
end;
begin
 init;
 read(n);
 for i:=1 to n do
 begin
  a[i].x:=i;
  read(a[i].h);
 end;
 for i:=1 to n do
 begin
  b[i].x:=i;
  read(b[i].h);
 end;
 sort(a,1,n);
 sort(b,1,n);
 for i:=1 to n do
  f[a[i].x]:=b[i].x;
 ans:=0;
 for i:=n downto 2 do
  for j:=1 to i-1 do
  if f[j]>f[i] then inc(ans);
 writeln(ans);
oover;
end.

