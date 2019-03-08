program block;
var n,m:integer;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
read(input,n);close(input);

rewrite(output);
write(output,m);close(output);
end.
