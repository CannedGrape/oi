program circle;
var n,m,k,x,c,i,j,z:longint;
    a,b:array[0..1000000]of longint;


 begin
   assign(input,'circle.in');
   reset(input);
   assing(output,'circle.out');
   rewrite(output);
   readln(n,m,k,x);
   for i:=0 to n-1 do
    begin
     a[i]:=i;
     b[i]:=i;
    end;
   c:=1;
   for i:=1 to k do
     c:=c*10;
   for i:=1 to c do
    begin
     for j:=0 to n-1 do
       a[(j+m)mod n]:=b[j];
     for z:=0 to n-1 do
       b[z]:=a[z];
    end;
   for i:=0 to n-1 do
     if a[i]=x then writeln(i);
  readln;
  close(input);
  close(output);
 end.
