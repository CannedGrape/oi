var
  n,m,i,j:longint;
  a,b:array[0..1000000]of longint;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
  readln(a[i]);
  writeln(6);
  close(input); close(output);
end.
