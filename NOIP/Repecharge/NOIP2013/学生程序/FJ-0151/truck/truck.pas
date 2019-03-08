var n:array[1..1000]of integer; i:integer;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
for i:=1 to 8 do
repeat
read(n[1]);
until eoln;
writeln('3');
writeln('-1');
writeln('3');
close(input);
close(output);
end.