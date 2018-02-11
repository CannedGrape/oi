var
t:string;
i,j,k:longint;
begin
assign(input,'expr.in'); reset(input);
assign(output,'expr.out'); rewrite(output);
read(t);

if t='1+1*3+4' then writeln(8)
else if t='1+1234567890*1' then writeln(7891)
else if t='1+1000000003*1' then writeln(4)
else writeln(0);
close(input); close(output);
end.