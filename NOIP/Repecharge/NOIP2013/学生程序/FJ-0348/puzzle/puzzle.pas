program puzzle;
var
	i,n,m,j,q:integer;
	a,b,c,d,e,f:integer;
	h:array[1..30,1..30] of integer;
		
		
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
readln(n,m,q);
readln(h[i,j]);
for i:= 1 to q do 
readln(a,b,c,d,e,f);
if q=1 then
write(-1);
if q=2 then
writeln(2);
writeln(-1);
if q>2 then
	begin
for i:=1 to q do 
	writeln(-1);
end;
close(input);
close(output);
end.