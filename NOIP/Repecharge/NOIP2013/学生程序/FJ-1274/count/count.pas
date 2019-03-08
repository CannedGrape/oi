var n,m,o,k,i,tot:longint;

begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
read(n,m);
tot:=0;
for i:=1 to n do
begin
o:=i;
repeat
k:=o mod 10;
o:=o div 10;
if k=m then tot:=tot+1;
until o=0;
end;
writeln(tot);
close(input);close(output);
end.