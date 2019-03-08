program flower;
var n,m,i,ans:longint;
   a,sum:array[0..110]of longint;
procedure f(x,z:longint);
var i,j,k:longint;
begin
 if z=m then ans:=(ans+1)mod 1000007
 else begin
  j:=m-z-sum[x];
  if j<0 then j:=0;
  k:=m-z;
  if k>a[x] then k:=a[x];
  for i:=j to k do
   f(x+1,z+i);
 end;
end;
begin
 assign(input,'flower.in');reset(input);
 assign(output,'flower.out');rewrite(output);
 readln(n,m);
 ans:=0;
 for i:=1 to n do
 begin
  read(a[i]);
  sum[i]:=sum[i-1]+a[i];
 end;
 for i:=1 to n do
  sum[i]:=sum[n]-sum[i];
 f(1,0);
 writeln(ans);
 close(input);close(output);
end.