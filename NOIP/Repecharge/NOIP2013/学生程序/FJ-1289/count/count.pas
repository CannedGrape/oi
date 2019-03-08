program count;
uses math;
var
a,b,y,p,q,i,j,k,x:longint;
m:string;
begin
assign(input,'count.in');
reset(input);
assign(output,'count.out');
rewrite(output);
read(a,b);
for i:=1 to a do
 begin
  k:=i;
  str(i,m);
  x:=length(m);
  for j:=x-1 downto 0 do
   begin
    p:=trunc(power(10,j));
    q:=k div p;
    if q=b then
     inc(y);
    k:=k-p*q;
   end;
  end;
write(y);
close(input);
close(output);
end.
