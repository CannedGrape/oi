
program flower;
var n,i,j:longint;
    h:array[1..100000] of longint;
    judge:boolean;
begin
assign(input,'flower.in');
reset(input);
assign(output,'flower.out');
rewrite(output);
readln(n);
for i:=1 to n do
 read(h[i]);
if h[1]<h[2] then
 begin
for i:=1 to n do
 for j:=n downto i do
if h[i]<h[j] then judge:=true else
begin
judge:=false;
break;
end;
end
else
begin
for i:=1 to n do
 for j:=n downto i do
if h[i]>h[j] then judge:=true else
begin
judge:=false;
break;
end;
end;
if (n=1) then writeln(n) else if (judge=false)  then writeln(0)
else writeln(3);
close(input);
close(output);
end.

