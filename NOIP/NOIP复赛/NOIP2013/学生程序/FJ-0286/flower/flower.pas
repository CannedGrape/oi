var h,f:array[1..100000] of longint;
    n,i,k:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  f[1]:=1;
  for i:=2 to n do
  if k=0 then
  if h[i]=h[i-1] then f[i]:=f[i-1]
  else begin
    f[i]:=f[i-1]+1;
    if h[i]>h[i-1] then k:=1
    else k:=-1
  end
  else if k=1 then
  if h[i]>=h[i-1] then f[i]:=f[i-1]
  else begin
    f[i]:=f[i-1]+1;k:=-1;
  end
  else if h[i]<=h[i-1] then f[i]:=f[i-1]
  else begin
    f[i]:=f[i-1]+1;k:=1;
  end;
  write(f[n]);
  close(input);close(output);
end.
