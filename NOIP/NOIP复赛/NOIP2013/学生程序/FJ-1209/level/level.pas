var
  x,n,m,y,i,j,count:longint;
begin
  assign(input'level.in');
  reset(input);
  assign(output'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
begin
  read(x);
  for j:=1 to x do read(y);
  readln;
end;
  write(m);
  close(input);
  close(output);
end.

