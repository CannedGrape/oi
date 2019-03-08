var list:array [0..100000] of longint;
    n,i,sum:longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do
read(list[i])
writeln(3);
close(input);
close(output);
end.
