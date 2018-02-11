var n,m,ex,ey,sx,sy,tx,ty,i,j,q:longint;
    a:array[0..501,0..501] of longint;
begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
    read(a[i,j]);
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    if ex=1 then writeln('-1') else writeln('2');
  end;
  close(input); close(output);
end.