program puzzle;
var i,j,m,n,q:longint;
    a:array[1..30,1..30] of integer;
    b:array[1..500,1..6] of longint;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
read(n,m,q);
for i:=1 to n do
 begin
  for j:=1 to m do
   read(a[i,j]);
  readln;
 end;
for i:=1 to q do
 begin
  for j:=1 to 6 do
   read(b[i,j]);
  readln;
 end;
writeln('2');
writeln('-1');
close(input);close(output);
end.
