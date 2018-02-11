var
  a:array [1..30000] of longint;
  n,m,i,j,k,q,x,y,z,min:longint;
  f:array [1..10000,1..10000] of longint;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if z>f[x,y] then
    begin
      f[x,y]:=z;
      f[y,x]:=z;
    end;
  end;
  for i:=1 to n do
  for j:=1 to n do
  if i<>j then
  for k:=1 to n do
  if (i<>k)and(j<>k)and(f[i,k]>f[i,j])and(f[j,k]>f[i,j]) then
  begin
    if f[i,k]>f[j,k] then min:=f[j,k] else min:=f[i,k];
    f[i,j]:=min;
    f[j,i]:=min;
  end;
  readln(q);
  for i:=1 to q do
  begin
    read(x,y);
    if f[x,y]=0 then a[i]:=-1 else a[i]:=f[x,y];
  end;
  close(input);
  for i:=1 to q do writeln(a[i]);
  close(output);
end.
