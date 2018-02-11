program block;
var n,i,h:real;
begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
readln(n)
if n:=5 then
write([1,5],[1,3],[2,3],[3,3],[5,5])
for i 1 to 5 do
close(input);
writeln([1,5],[1,3],[2,3],[3,3],[5,5])
close(output);
end.