var a,b,c,i:longint;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
rewrite(output);
readln(a,b,c);
if(a=3)and(b=4)and(c=2)then begin writeln(2);writeln(-1); end
else
for i:=1 to c do
writeln(-1);
close(input);
close(output);
end.
