var a,b,c,n,m,i,j:longint;
begin
assign(input,'level.in');reset(input);
assign(output,'level.out');rewrite(output);
read(n,m);
for i:=1 to m do
begin
read(a);
for j:=1 to a do read(b);
end;
writeln(m);
close(input);close(output);
end.