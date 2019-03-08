var h,g:array[1..1000000]of longint;
    i,n,f,r,j:longint;
begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  for i:=1 to n do g[i]:=h[i];
  f:=0;
  if h[1]<h[2] then f:=1;
  for j:=1 to n do
   for i:=2 to n-1 do
    if g[i]>h[i-1] then
     if g[i]>h[i+1] then inc(f);
  r:=0;
  if h[1]>h[2] then r:=1;
  for j:=1 to n do
   for i:=2 to n-1 do
    if g[i]<h[i-1] then
     if g[i]<h[i+1] then inc(r);
  if f>r then writeln(f) else writeln(r);

close(input);
close(output);
end.
