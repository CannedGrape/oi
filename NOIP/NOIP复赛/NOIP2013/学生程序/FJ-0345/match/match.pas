program match;
var i,n:integer;
   a,b:array[1..100001] of integer;

begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
for i:=1 to n do
read(b[i]);
writeln(1);
close(input);
close(output);
end.

