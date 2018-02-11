var
a,b,c,d,i,j:longint;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
readln(a,b);
for i:=1 to b do
begin
read(c);
for j:=1 to c do
read(d);
end;
writeln(b);
close(input);close(output);
end.
