program number;
var a,b,c:array[1..100000] of longint;
    i,j,x,y,n,p,max:longint;
begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 read(n,p);
 for i:=1 to n do
  read(a[i]);
 for i:=2 to n do
  a[i]:=a[i]+a[i-1];
  b[1]:=a[1];
 for i:=2 to n do
   b[i]:=b[i-1]+a[i-1];
 max:=b[1];
 for i:=1 to n do
  if b[i]>max then max:=b[i];
 if max>p then writeln(max-p)
  else write(max);
close(input);close(output);
end.
