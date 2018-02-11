var
a,b,i,j,m,l,n:longint;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
readln(n,a);
b:=n;
repeat
if b mod 10=0 then
m:=m+1;
b:=b div 10;
until b=0;
for i:=1 to n do
for j:=1 to m do
begin
if n mod 10=a then l:=l+1;
n:=n div 10;
end;
writeln(l);
close(input);close(output);
end.
