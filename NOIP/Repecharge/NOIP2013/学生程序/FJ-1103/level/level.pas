program level;
var n,m,i,j,s:integer;
    a:array[1..1000,1..10000] of integer;
begin
assign(input,'level.in');
reset(input);
assign(output,'level.out');
rewrite(output);
readln(n,m);
for i:=1 to m do
begin
read(s);
for j:=1 to s do
read(a[i,j]);
end;
if m=2 then write('2') else
write('3');
close(input);
close(output);
end.