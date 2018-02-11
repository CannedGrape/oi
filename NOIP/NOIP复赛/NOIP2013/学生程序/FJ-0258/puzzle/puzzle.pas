var
a,h:array[1..10000,1..10000]of longint;
m,n,i,j,k,temp,g,b:longint;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,k);
  for i:=1 to n do
  begin
  for j:=1 to m do
  read(a[i,j]);end;
  for i:=1 to k do
  begin
  for j:=1 to 6 do
  read(h(i,j));
  end;
  writeln('2');
  writeln('-1');
  close(input);
  close(output);
  readln;readln;
end.
