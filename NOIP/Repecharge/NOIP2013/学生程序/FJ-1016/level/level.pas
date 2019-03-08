var
  n,m,i,j:integer;
  s:array[1..1000]of integer;
  a:array[1..1000,1..1000]of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(s[i]);
    for j:=1 to s[i] do
      read(a[i,j]);
  end;
  writeln(m);
  close(input);
  close(output);
end.