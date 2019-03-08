var
n,m,k,x,h:longint;
s,l:int64;

function gcd(a,b:longint):longint;
begin
if b=0 then exit(a);
gcd:=gcd(b,a mod b);

end;


begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
read(n,m,k,x);
if gcd(10,n)=1 then k:=k mod (n-1);
s:=1;
l:=10 mod n;
h:=k and 1;
if h=1 then s:=(s*l) mod n;
k:=k shr 1;

while k>0 do
begin
l:=(l*l) mod n;
h:=k and 1;
k:=k shr 1;
if h=1 then s:=(s*l) mod n;



end;
s:=(s*(m mod n)) mod n;
write(((x mod n)+(s mod n)) mod n);

close(input);
close(output);

end.