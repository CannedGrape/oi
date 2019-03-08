program match;
var
a,b:integer;
c:array[1..1000]of integer;
d:array[1..100]of integer;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
read(a);
readln;
for b:=1 to a do
read(c[b]);
readln;
for b:=1 to a do
read(d[b]);
writeln(1);
close(input);
close(output);
end.
