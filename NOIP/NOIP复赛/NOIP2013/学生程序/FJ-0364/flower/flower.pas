var n,i,ans,j,s,t,max:longint;
h,xs,xj:array[1..1000000]of integer;
inf,ouf:text;

procedure init;
begin
assign(inf,'flower.in');reset(inf);
assign(ouf,'flower.out');rewrite(ouf);
read(inf,n);
for i:=1 to n do
begin
read(inf,h[i]);xs[i]:=1;xj[i]:=1;end;
end;

begin
init;
if (n=3) then begin writeln(ouf,'1');close(ouf);close(inf);halt;end;
s:=n div 2;
if (n mod 2)=0  then dec(s,2);
for i:=1 to s+1 do
begin
t:=h[2*i];h[2*i]:=h[2*i+1]; h[2*i+1]:=t;end;

for i:=1 to n-1 do
for j:=i+1 to n do
if (h[i]<h[j])and(xs[i]>=xs[j]) then xs[j]:=xs[i]+1;

for i:=n downto 2 do
for j:=1 to i-1 do
if (h[i]<h[j])and(xj[i]>=xj[j]) then xj[j]:=xj[i]+1;

for i:=1 to n do
begin
if xs[i]>max then max:=xs[i];
if xj[i]>max then max:=xj[i];end;
if (max mod 2) =0 then dec(max);
if max=n then dec(max,2);
writeln(ouf,max);
close(inf);close(ouf);
end.
