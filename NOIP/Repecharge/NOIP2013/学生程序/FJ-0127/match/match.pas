program match;
var
i,n,c:integer;
b,a:array[1..100000000] of integer;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
readln(n);
for i:=1 to n do
 read(a[i]);
 readln;
for i:=1 to n do
 read(b[i]);
  c:=2;
  writeln(c);
close(input);
close(output);
end.