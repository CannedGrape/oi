var a:array[1..100000] of longint;
    f:array[1..100000] of longint;
    n,i,j,k:longint;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  f[1]:=a[1];
  for i:=2 to n do
    if a[i]<a[i-1] then f[i]:=f[i-1] else f[i]:=f[i-1]+a[i]-a[i-1];
  writeln(f[n]);
  close(input);close(output);
end.
