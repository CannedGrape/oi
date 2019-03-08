var
  n,m,i,j:longint;
  a,b:array[1..1000]of longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to 5 do
  read(a[i]);
  for j:=1 to m do
  for i:=1 to n do
  read(b[i]);
  writeln(m);
  close(input);close(output);
end.
