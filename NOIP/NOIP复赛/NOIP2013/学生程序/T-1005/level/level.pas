var
n,m,i:longint;
t:string;
begin
assign(input,'level.in'); reset(input);
assign(output,'level.out'); rewrite(output);
readln(n,m);
for i:=1 to m do
readln(t);
writeln(m);
close(input); close(output);
end.