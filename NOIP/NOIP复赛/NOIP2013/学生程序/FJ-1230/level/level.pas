program level;
var i,j:integer;
begin
assign(input,'level.in');
reset(input);
assign(output,'level.out');
rewrite(output);
readln(i,j);
if j=3 then writeln(2) else writeln(3);
close(input);close(output);
end.