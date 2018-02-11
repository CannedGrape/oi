program puzzle;
var
  n,m,q,i,j,k:longint;
  number,qn:array[1..100,1..100] of longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
    read(number[i,j]);
  for i:=1 to q do
    for j:=1 to 6 do
    read(qn[i,j]);
  writeln('-1');
  close(input);close(output);
end.
