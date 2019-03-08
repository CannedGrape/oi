program turck;
var n,m,q,d,e,f,u:integer;
    i,j,k,x,y,z:array[1..100]of integer;
    a,b:array[1..100,1..100]of integer;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
read(n,m);
readln;
for d:=1 to m do
begin
read (i[d],j[d]);
read (a[i[d],j[d]]);
readln;
end;
for d:=1 to n do
for e:=1  to n do
begin
if a[d,e]=0 then a[d,e]:=-1;
end;
for u:=1 to n do
for d:=1 to n do
for e:=1 to n do
if (a[d,e]<>-1)and(a[e,u]<>-1) then
begin
if a[d,e]>a[e,u]
then a[d,u]:=a[e,u]
else a[d,u]:=a[d,e];
end;
read(q);
readln;
for f:=1 to q do
begin
read(x[d],y[d]);
readln;
end;
 for f:=1 to q do
 writeln(a[x[f],y[f]]);
 close(input);
 close(output);
end.
