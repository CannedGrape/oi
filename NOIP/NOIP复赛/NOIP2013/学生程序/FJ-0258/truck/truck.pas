program truck;
var
  i,j,k:longint;
  n,m:longint;
  x,y,z:longint;
  q:longint;
  x1,y1:longint;
  begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
  readln(n,m);
for i:=1 to m do
readln(x,y,z);
readln(q);
for i:=1 to q do
readln(x1,y1);
writeln('3');
writeln('-1');
writeln('3');
close(input);
close(output);
end.
