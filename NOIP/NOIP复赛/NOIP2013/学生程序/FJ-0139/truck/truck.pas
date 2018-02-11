var a,b,c,e,f:array[1..1000] of longint;
i,j,k,l,h,m,n,o,p,q,x,y,tt,xx:longint;
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
readln(n,m);
for i:=1 to m do
readln(a[i],b[i],c[i]);
readln(k);
for i:=1 to k do
readln(e[i],f[i]);
for xx:=1 to k do
begin
if (f[xx]>m) or (e[xx]>m) then begin
writeln('-1');continue;
end;
p:=a[e[xx]];q:=c[e[xx]];
repeat
if q>c[a[p]] then q:=c[a[p]];p:=b[p];
until a[p]=f[xx];
writeln(q);
end;
close(input);close(output);
end.
