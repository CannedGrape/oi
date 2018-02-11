program circle;
var
 a,b:array[0..1000000] of longint;
 z,y,i,j,n,m,k,x:longint;
begin
 assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
readln(n,m,k,x);
 y:=1;
 if k=1 then y:=10
 else for i:=1 to k do
 y:=10*y;
 for i:=0 to n-1 do
 a[i]:=i;
 for i:=1 to y do
  x:=x+m;
  if x>=n then x:=x mod n;
  writeln(x);
 close(input);close(output);
end.
