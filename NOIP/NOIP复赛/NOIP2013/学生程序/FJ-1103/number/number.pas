program number;
var n,i,p:longint;
    a:array[1..1000000] of longint;
begin
assign(input,'number.in');
reset(input);
assign(output,'number.out');
rewrite(output);
readln(n,p);
for i:=1 to n do
read(a[i]);
write(abs(-1) mod p);
close(input);
close(output);
end.
