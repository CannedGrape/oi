program block;
var n,i,k,max,count,l,z:longint;
    h:array[1..100000] of longint;
begin
assign(input,'block.in');
reset(input);
assign(output,'block.out');
rewrite(output);
readln(n);
count:=0;
max:=-maxlongint;;
for i:=1 to n do
  read(h[i]);
for i:=1 to n do
 if h[i]>max then
begin
 k:=i;
 max:=h[i];
end;
inc(count,max);
 for l:=1 to  k-1 do
  if h[l]>h[l+1] then inc(count,h[l]-h[l+1]);
for z:=k to n-1 do
 if h[z]<h[z+1] then inc(count,h[z+1]-h[z]);
writeln(count);
close(input);
close(output);
end.


