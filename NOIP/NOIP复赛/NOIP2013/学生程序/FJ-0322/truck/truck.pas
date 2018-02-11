var
  n,m,i,q,x,y,z,w:longint;
  d:array[0..10000] of longint;
  u:array[0..10000] of boolean;
  f:array[0..10000,0..10000] of longint;
function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;

function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;

procedure dis;
var k,max,j:longint;
begin
  d[x]:=0; u[x]:=false;
  while true do
  begin
    k:=0; max:=-maxlongint;
    for j:=1 to n do
    if (d[j]>max) and (u[j]) then
    begin
      max:=d[j];
      k:=j;
    end;
    if k=0 then break;
    u[k]:=false;
    for j:=1 to n do
    if u[j] and (d[j]<f[k,j]) then d[j]:=min(f[k,j],d[k]);
  end;
end;

begin
assign(input,'truck.in'); reset(input);
assign(output,'truck.out'); rewrite(output);
  read(n,m);
  fillchar(f,sizeof(f),128);
  for i:=1 to m do
  begin
    read(x,y,z);
    f[x,y]:=max(f[x,y],z);
    f[y,x]:=max(f[y,x],z);
  end;
  read(q);
  for w:=1 to q do
  begin
    read(x,y);
    for i:=1 to n do
    d[i]:=f[x,i];
    fillchar(u,sizeof(u),true);
    dis;
    if d[y]<0 then writeln('-1')  else
    writeln(d[y]);
  end;
close(input); close(output);
end.