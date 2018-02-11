program b4;
var j,b:integer;f1,f2:text;
s,k,i,x:longint;
begin
assign(f1,'count.in');
assign(f2,'count.out');
reset(f1);
rewrite(f2);
readln(f1,x,b);
for i:=1 to x do
begin
k:=i;
while k<>0 do
begin
j:=k mod 10;
if j=b then s:=s+1;
k:=k div 10;
end; end;
write(f2,s);
close(f1);
close(f2);
end.
