var h:array[-101..1000000] of longint;
n,i,ans:longint;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input); rewrite(output);
  ans:=0;
  readln(n);
  for i:=1 to n do
    read(h[i]);
  for i:=2 to n-1 do
    if  ((h[i]>h[i-1]) and (h[i]>h[i+1]))  or((h[i]<h[i-1]) and (h[i]<h[i+1])) then
    inc(ans);
  if ans=0 then writeln(0) else
    writeln(ans+2);
  close(input); close(output);
end.
