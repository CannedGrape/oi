program level;
var n,m,a,b,i,j,ans:integer;
s,d:set of integer;
begin
assign(input,'level.in');
reset(input);
assign(output,'level.out');
rewrite(output);
readln(n,m);
s:=[]; d:=[];
for i:=1 to m do
begin
read(a);
for j:=1 to a do
read(b);
d:=s+[b];
s:=d-s;
readln;
for y:=1 to 1000 do
if y in s then
ans:=ans+1;
writeln(ans+1);
close(input);
close(output);
end.

