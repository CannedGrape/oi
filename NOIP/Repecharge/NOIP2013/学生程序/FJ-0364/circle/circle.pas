var i,j,n,m,k,x,ni:longint;
inf,ouf:text;
procedure init;
begin
assign(inf,'circle.in');reset(inf);
assign(ouf,'circle.out');rewrite(ouf);
read(inf,n,m,k,x);
end;

begin
init;
ni:=1;
for i:=1 to k do ni:=ni*10;
for j:=1 to ni do
begin
x:=x+m;
if x>n then x:=x-n;
end;

writeln(ouf,x);
close(inf);close(ouf);

end.
