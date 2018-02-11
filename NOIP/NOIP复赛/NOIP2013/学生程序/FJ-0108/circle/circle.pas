var t,n,m,k,x:int64;
    i:longint;
begin
t:=1;
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
read(n,m,k,x);
if k<=18 then
begin
for i:=1 to k do
t:=t*10;
writeln((x+(t*m)) mod n);
end
else writeln((x+(10*m)) mod n);
close(input);
close(output);
end.
