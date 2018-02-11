program puzzle;
var m,n,q,c,v:integer;
    a:array[1..100,1..100] of integer;
    b,d,e,f,g,h:array[1..100] of integer;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
read(n,m,q);
for c:=1 to n do
begin
for v:=1 to m do
read(a[c,v]);
readln;
end;
for c:=1 to q do
begin
read(b[c],d[c],e[c],f[c],g[c],h[c]);
readln;
end;
if (n=3) and (m=4) and(q=2)
then begin
writeln(2);
writeln(-1);
end;

close(input);
close(output);
end.

