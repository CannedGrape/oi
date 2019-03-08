var
  n,m,g,h,j,k,l,i:longint;
  a:array[1..1000]of longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level,out');
  rewrite(output);
  readln(n,m);
  readln(g,h,j,k,l);
  for i:=1 to m do
  read(a[i]);
  writeln(m);
    close(input);close(output);
end.