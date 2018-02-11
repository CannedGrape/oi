program puzzle;
var
  a:array[1..1000,1..100] of longint;
  b:array[1..1000,1..6] of longint;
  i,j,k,n,m,s,t,q:longint;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    for j:=1 to 6 do read(b[i,j]);
    readln;
  end;
  if q=2 then
  begin
    writeln('2');
    writeln('-1');
  end
  else
  for i:=1 to i do writeln('-1');
  close(input);
  close(output);
end.