program block;
var num,amax,k,n,i,j,l:longint;
    h,a,b:array[0..1000000]of longint;
  begin
   assign(input,'block.in');reset(input);
  assign(output,'blosk.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
    read(b[i]);
    a[i]:=b[i];
    end;
  for i:=1 to n do
   begin
   l:=i;
   for j:=i to n do
    if b[l]<b[j] then l:=j;
   k:=b[i];b[i]:=b[l];b[l]:=k;
   end;
   amax:=b[1];
 for j:=1 to amax do
  for i:=1 to n do
   if h[i]<a[i] then
   begin
   inc(h[i]);
   inc(num);
   if h[i]=h[i-1] then num:=num-1;
   end;
writeln(num);
  close(input);close(output);
  end.
