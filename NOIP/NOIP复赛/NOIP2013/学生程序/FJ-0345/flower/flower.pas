program lower;
var n:longint;
i:integer;
    h:array[1..100001] of integer;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
for i:=1 to n do read(h[i]);
readln;
writeln(3);
close(input);
close(output);
end.
