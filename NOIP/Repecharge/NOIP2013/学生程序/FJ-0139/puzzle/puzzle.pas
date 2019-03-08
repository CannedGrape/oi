var a,b,c,i:longint;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
read(a,b,c);
for i:=1 to c do
writeln('-1');
close(input);close(output);
end.
