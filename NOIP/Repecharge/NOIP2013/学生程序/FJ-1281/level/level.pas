var a,b:longint;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
readln(a,b);
writeln(b);
close(input);close(output);
end.