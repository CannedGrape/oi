program level;
var
a,a1:longint;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
readln(a,a1);
write(a1);
close(input);close(output);
end.
