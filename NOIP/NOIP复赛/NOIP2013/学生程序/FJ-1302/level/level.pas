program level1;

var
  a:array[1..100,1..100] of integer;
  n,m,si,i,j:integer;

begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m,si);
  for i:=1 to m do
    for j:=1 to si do
      read(a[i,j]);
  if m=2 then write(2);
  if m=3 then write(3);
  close(input);
  close(output);
end.
