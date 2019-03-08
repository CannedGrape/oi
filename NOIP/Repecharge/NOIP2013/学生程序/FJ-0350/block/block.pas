var
n,x,i,h:longint;
sum:int64;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
read(n);
read(x);
sum:=x;
for i:= 2 to n do
begin
read(h);
if h>x then inc(sum,h-x);
x:=h;



end;
write(sum);
close(input);
close(output);









end.
