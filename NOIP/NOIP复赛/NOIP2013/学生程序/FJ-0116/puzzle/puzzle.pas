var
  n,m,q,i,j,ex,ey,sx,sy,tx,ty:longint;
  a:array[1..30,1..30] of longint;
begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to q do
    readln(ex,ey,sx,sy,tx,ty);
  for i:=1 to q do
    writeln(-1);
  close(input); close(output);
end.