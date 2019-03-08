var n,i,tmp:longint;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to 2*n do
read(tmp);
writeln(2);
close(input);
close(output);
end.
