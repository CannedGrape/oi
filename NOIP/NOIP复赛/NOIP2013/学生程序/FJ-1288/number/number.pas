var
a,b,c,n,p,i,j:longint;
x:array[1..1000000] of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  read(n,p);
  for i:=1 to n do
    read(x[i]);
  for j:=1 to n do
  for i:=1 to j do
    a:=a+x[i];
  writeln(a);
  close(input);
  close(output);
end.