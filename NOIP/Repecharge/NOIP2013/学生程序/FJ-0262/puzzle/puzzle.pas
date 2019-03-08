program puzzle;
var n,m,q:integer;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
read(input,n);close(input);
rewrite(output);
write(output,q);close(output);
end.