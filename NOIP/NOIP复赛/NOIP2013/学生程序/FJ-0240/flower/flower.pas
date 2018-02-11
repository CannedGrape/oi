program flower;
var
n,k,i:integer;
f1,f2:text;
a:array[1..1000]of integer;
begin
assign(f1,'flower.in');reset(f1);
assign(f2,'flower.out');rewrite(f2);
readln(n);
for i:=1 to n do read(a[i]);close(f1);
k:=0; i:=0;
while i<=n-k do
begin
inc(i);
if (a[2*i-k-1]<=a[2*i-k])and(a[2*i-k+1]>=a[2*i-k])or
(a[2*i-k-1]>=a[2*i-k])and(a[2*i-k+1]<=a[2*i-k]) then inc(k);
if 2*i-k+1=n-k then break;
end;
writeln(n-k);close(f2);
end.