var n,i,m,x,k,t,j:longint;a:array[0..1000000]of longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  for i:=0 to n-1 do
  a[i]:=i;
  t:=trunc(exp(k*ln(10))) mod n;
  for j:=1 to t do
    for i:=1 to n-1 do
    a[i]:=(a[i]+m) mod n;
  writeln(a[x]);
  close(input);close(output);
end.

