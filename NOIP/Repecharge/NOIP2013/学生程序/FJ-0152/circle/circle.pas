program circle;
var n,m,k,x,y,z,b,d:longint;
  a:array[0..1000]of longint;
  c:array[0..1000]of longint;
 begin
 assign(input,'circle.in');
 reset(input);
 assign(output,'circle.out');
 rewrite(output);
 read(n,m,k,x);
 z:=1;
 for y:=1 to k do
 z:=z*10;
 for y:=0 to n-1 do
 a[y]:=y;
 for y:=1 to z do
 begin
 for b:=0 to n-m-1 do
 begin
 c[b]:=a[b];
 a[b]:=a[b+m];
 end;
 for d:=n-m to n-1 do
 a[d]:=c[(d+m) mod n ];
 end;
 write(a[x]);
 close(input);
 close(output);
 end.


