var a,b:array[0..100000]of longint;
    n,k,x,s,j,c,l,sum,i,d,m,q:longint;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
s:=1;
read(n,m,k,x);
for i:=1 to n do
a[i-1]:=i-1;
for i:=1 to k-1 do
s:=s*10;
fillchar(a,sizeof(a),0);
fillchar(b,sizeof(b),0);
d:=0;
if (n mod m=0) then c:=n div m;
if (m mod 2<>0) or (m=2) then c:=n;
if (m mod 2=0) then
  begin
     d:=m div 2;
     c:=n*d div m;
  end;
if (s mod c=0) then write(x);
if (s mod c<>0) then
 begin
  for i:=1 to s do
   for j:=1 to m do
    b[j-1]:=a[n-m+j-1];
 for l:=1 to n do
 if (b[l-1] div x=1) and(b[l-1] mod x=0) then
 write(l-1);
 end;
close(input);
close(output);
end.










