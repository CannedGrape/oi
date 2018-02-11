program match;
var
  n,i,j,k:longint;
  a,b:array[1..2,1..100000] of longint;
procedure sun;
var
i,j,p:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
      if a[1,i]<a[1,j] then
      begin
        p:=a[1,i];a[1,i]:=a[1,j];a[1,j]:=p;
        p:=a[2,i];a[2,i]:=a[2,j];a[2,j]:=p;
      end;
  for i:=1 to n do
    for j:=i+1 to n do
      if b[1,i]<b[1,j] then
      begin
        p:=b[1,i];b[1,i]:=b[1,j];b[1,j]:=p;
        p:=b[2,i];b[2,i]:=b[2,j];b[2,j]:=p;
      end;
end;


begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
  read(a[1,i]);
  a[2,i]:=i;
  end;
  for i:=1 to n do
  begin
  read(b[1,i]);
  b[2,i]:=i;
  end;
  sun;
  for i:=1 to n do
  if a[2,i]<>b[2,i] then
  inc(k);
  writeln(k-1);
  readln;
  close(input);close(output);
end.
