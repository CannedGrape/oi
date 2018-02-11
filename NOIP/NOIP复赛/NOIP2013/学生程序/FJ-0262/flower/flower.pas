program flower;
var n,m:integer;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
read(input,n);close(input);
rewrite(output);
write(output,m);close(output);
end.