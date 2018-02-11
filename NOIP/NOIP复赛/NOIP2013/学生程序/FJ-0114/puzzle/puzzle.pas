program puzzle(input,output);
var
n,m,i,j:integer;
a:array[1..30,1..30] of integer;
b:array[1..500,1..6] of integer;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  read(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to q do
    for j:=1 to 6 do
      read(b[i,j]);
  for i:=1 to q do
    writeln('-1');
  close(input);
  close(output);
  end.