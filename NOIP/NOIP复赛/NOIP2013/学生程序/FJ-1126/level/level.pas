var a,b,c,i,j,n,m,x,y,z,h,k,z1:longint;
    ab,ac,pd:array [0..1000,0..1000] of longint;
    max:array [0..1000] of longint;
procedure dg(x,y:longint);
var a,b,c,i,j:longint;
begin
 max[x]:=y;
 if y>z1 then z1:=y;
 for i:=1 to n do
  if (pd[i,x]=1) and (y+1>max[i]) then dg(i,y+1);
end;
begin
 assign(input,'level.in');
 assign(output,'level.out');
 reset(input);
 rewrite(output);
 read(n,m);
 for i:=1 to m do
  begin
   read(ab[i,0]);
   for j:=1 to ab[i,0] do
    begin
     read(ab[i,j]);
     ac[i,ab[i,j]]:=1;
    end;
  end;
 for i:=1 to m do
  for j:=ab[i,1] to ab[i,ab[i,0]] do
   if ac[i,j]=0 then
    for h:=1 to ab[i,0] do
     pd[j,ab[i,h]]:=1;
 for i:=1 to n do
  if max[i]=0 then dg(i,1);
 writeln(z1);
 close(input);
 close(output);
end.

