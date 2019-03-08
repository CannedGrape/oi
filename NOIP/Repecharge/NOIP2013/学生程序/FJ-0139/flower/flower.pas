var  a:array[1..10000] of longint;
n,i,j,l,m:longint;k:real;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
write(n div 2);
close(input);close(output);
end.
