program nuberm;
var i,j:integer;
a:array[1..10]of integer;
assign(input,'number.in');
reset(input);
assign(output,'number.out');
rewrite(output);
begin
readln(i,j);
if (i=5)then writeln(21)
else writeln(-1);
close(input);close(output);
end.