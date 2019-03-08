var a,b:longint;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);

readln(a);
readln(b);
if b=2 then writeln(1)
else if b=1 then writeln(2)
else writeln(0);

close(input);
close(output);
end.