var
count,a,i,n,j,l,c:longint;
x:array[1..10] of longint;
begin
 assign(input,'count.in');
 reset(input);
 assign(output,'count.out');
 rewrite(output);
read(n,a);
count:=0;
for i:=1 to n do
begin
l:=1;
j:=i;
while j<>0 do
begin
x[l]:=j mod 10;
j :=j div 10;
inc(l);
end;
for c:=1 to 7 do
if x[c]=a then inc(count);
end;
writeln(count);
close(input);
close(output);
end.
