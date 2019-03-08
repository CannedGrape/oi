program circle;
var a,b,c,n,m,k,x:longint;
begin
 assign(input,'circle.in');
 reset(input);
 assign(output,'circle.out');
 rewrite(output);
 read(n,m,k,x);
 b:=x-1;
 c:=1;
 for a:=1 to k do
  c:=c*10;
 b:=b+1;
 for a:=1 to c do
   b:=m+b;
 while b>n do
  b:=b-n;
 write(b);
 close(input);
 close(output);
end.
