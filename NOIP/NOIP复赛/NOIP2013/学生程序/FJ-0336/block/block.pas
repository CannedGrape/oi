var a,h,b:array[1..10000]of longint;
    n,i,f,j,k,m,min,max,s:longint;
begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
  readln(n);min:=10001;
  for i:=1 to n do read(h[i]);
  f:=-1;
  for i:=1 to n do
    if h[i]>h[i+1] then inc(f);
  for k:=1 to f do
   for i:=1 to n-1 do
   begin
    if h[i]>h[i+1] then a[k]:=i;
    if a[k]>m then m:=a[k];
   end;
  for i:=1 to n-1 do
   if h[i+1]<h[i] then min:=h[i+1];
  for i:=1 to a[k] do
   if h[i]>max then max:=h[i];
  b[1]:=max;
  if f>2 then
   for k:=2 to f do
   begin
    max:=0;
    for i:=a[k] to a[k+1] do
     if h[i]>max then max:=h[i];
    b[k]:=max;
   end;
  for k:=1 to f do s:=b[k]+s+min;
  writeln(s);
close(input);
close(output);
end.
