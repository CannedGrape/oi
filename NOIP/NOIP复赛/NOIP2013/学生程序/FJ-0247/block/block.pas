program block;
  var
    max,n,i,j:longint;
    a:array[1..10000] of longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
max:=a[1];
for j:=2 to n do
begin
if max<a[j] then
max:=a[j];
end;
write(max);
close(input);close(output);
end.

