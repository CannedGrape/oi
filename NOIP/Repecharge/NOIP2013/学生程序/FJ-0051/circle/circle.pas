var
   a:array[0..1000010]of longint;
   i,j,n:longint;
   x,k,m:int64;
function ksm(x,y:int64):int64;
var
  kk:int64;
begin
   if y=0 then exit(1);
   if y=1 then exit(x);
   kk:=ksm(x,y div 2);
   if y mod 2=1 then exit((kk*kk mod n)*x mod n) else
     exit(kk*kk mod n);
end;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
   readln(n,m,k,x);
   j:=x;
   for i:=0 to n-1 do
   begin
      a[i]:=j;
      inc(j);
      if j>n-1 then j:=0;
   end;
   k:=ksm(10,k);
   k:=k*m mod n;
   k:=(k+n) mod n;
   writeln(a[k]);
close(input);close(output);
end.
