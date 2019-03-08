var
i,j,n,k,a,b,s:longint;
begin
assign(input,'count.in'); reset(input);
assign(output,'count.out'); rewrite(output);
read(a,b);
for i:=1 to a do
begin
j:=i;
while j<>0 do
begin

if j mod 10=b then s:=s+1;
j:=j div 10;
end;
end;
writeln(s);
close(input); close(output);
end.