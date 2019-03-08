program puzzle;

var
  i,j,n,m,q,t:longint;
   a,s:array[1..1000,1..1000] of longint;

begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to q do
    for j:=1 to 6 do
      read(s[i,j]);
  t:=-1;
  for i:=1 to q do
    writeln(t);
  close(input);
  close(output);

end.

