var
a,b,i,n,j,z:longint;
x:array[1..100]of longint;
begin
assign(input,'level.in');
reset(input);
assign(output,'level.out');
rewrite(output);
read(a,b);
for i:=1 to a do
begin
read(n);
for j:=1 to n do
begin
read(z);
x[z]:=x[z]+1;
end;
end;
j:=0;
for i:=1 to a do
if x[a]>=2 then j:=j+1;
write(j);
close(input);
close(output);
end.
