program bbai;
var n,m,q,q1,q2,m1,m2,x,y,i,j:longint;
a:array[0..50,0..50]of longint;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
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
readln(x,y,q1,q2,m1,m2);
writeln(-1);
end;
close(input);close(output);
end.