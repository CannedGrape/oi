program count;
var x:0..9;
    n,i,j,b,c,k,d,e,f:longint;
    a:array[1..1000000] of longint;
begin
   assign(input,'count.in');
   reset(input);
   assign(output,'count.out');
   rewrite(output);
   k:=0;
   read(n,x);
   close(input);
   for i:=1 to n do
   begin
   a[i]:=i mod 10;
   if a[i]=x then
   k:=k+1;
   end;
   for j:=10 to n do
   begin
   a[j]:=j div 10 mod 10;
   if a[j]=x then
   k:=k+1;
   end;
   for b:=100 to n do
   begin
   a[b]:=b div 100 mod 10;
   if a[b]=x then
   k:=k+1;
   end;
   for c:=1000 to n do
   begin
   a[c]:=c div 1000 mod 10;
   if a[c]=x then
   k:=k+1;
   end;
   for d:=10000 to n do
   begin
   a[d]:=d div 10000 mod 10;
   if a[d]=x then
   k:=k+1;
   end;
   for e:=100000 to n do
   begin
   a[e]:=e div 100000 mod 10;
   if a[e]=x then
   k:=k+1;
   end;
   for f:=1000000 to n do
   begin
   a[f]:=f div 1000000 mod 10;
   if a[f]=x then
   k:=k+1;
   end;
   write(k);
   close(output);
end.



