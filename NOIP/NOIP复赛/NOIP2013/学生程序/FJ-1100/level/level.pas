var m,n,i,j,level:integer;
a:array[1..1000,0..1000]of integer;
l:array[1..1000]of integer;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(a[i,0]);
      for j:=1 to a[i,0] do
        read(a[i,j]);
    end;
  for i:=1 to m do
    for j:=1 to a[i,0] do
      inc(l[a[i,j]]);
  level:=0;
  for i:=1 to n do
    if l[i]>level then level:=l[i];
  writeln(level);
  close(input);
  close(output);
end.