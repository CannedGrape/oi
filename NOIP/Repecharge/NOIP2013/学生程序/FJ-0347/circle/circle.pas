program lai;
var n,m,k,x,t,lp,lun,rest,now,i,rmod:longint;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
read(n,m,k,x);
t:=1;
while ((n*t) mod m<>0) do
inc(t);
lp:=(n*t) div m;
rmod:=1;
for i:=1 to k do
rmod:=(10*rmod) mod lp;
rest:=rmod;
now:=(x+rest*m) mod n;
writeln(now);
close(input);
close(output);
end.
