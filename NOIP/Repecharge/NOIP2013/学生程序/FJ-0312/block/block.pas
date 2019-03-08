program block;
var i,j,n,m,k:longint;
    f,h:array[0..100005]of longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);readln;
  f[1]:=h[1];
  for i:=2 to n do
  if h[i]<=h[i-1] then f[i]:=f[i-1]else f[i]:=f[i-1]+(h[i]-h[i-1]);
  write(f[n]);
close(input);close(output);
end.
