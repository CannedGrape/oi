program puzzle;
var n,m,q,i,j,k,l:longint;
    a,b:array[1..100000,1..100000] of longint;
    c:array[1..100000] of longint;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);

readln(n,m,q);
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
for i:=1 to q do
  if (b[i,3]=b[i,5]) and (b[i,4]=b[i,6]) then c[i]:=0 else c[i]:=-1;
for i:=1 to q do
 writeln(c[i]);
close(input);
close(output);
end.

