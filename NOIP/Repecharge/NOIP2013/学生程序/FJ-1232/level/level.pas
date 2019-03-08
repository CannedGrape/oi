program exam1;
var max,t,w:array[0..2000] of longint;
    b:array[0..2000,0..2000] of boolean;
    bb:array[0..2000] of boolean;
    f:array[0..2000] of longint;
    i,j,m,n,k,max1,x:longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  read(n,m);
  for i:=1 to m do
  begin
  read(k);
  for j:=1 to k do
  begin
  read(x);
  if j=1 then t[i]:=x;
  if j=k then w[i]:=x;
  b[i,x]:=true;
  bb[x]:=true;
  end;
  end;
  for i:=1 to n do
  f[i]:=1;
  for i:=1 to n do
  if b[1,i]=true  then inc(f[i]);
  max[1]:=2;
  max1:=max[1];
  for i:=2 to m do
  begin
  max[i]:=2;
  for j:=t[i] to w[i] do
  if (bb[j]=true)and(b[i,j]=false) then
     begin
     if max[i]<f[j]+1 then max[i]:=f[j]+1;
     end;
  for j:=1 to n do
  if b[i,j] then f[j]:=max[i];
  if max1<max[i] then max1:=max[i];
  end;
  writeln(max1);
  close(input);
  close(output);
end.


