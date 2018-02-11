program puzzle;
var ex,ey,sx,sy,tx,ty,b,c,t,s,i,n,m:integer;
    q:integer;
    a:array[1..30,1..30] of word;
BEGIN
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
read(m,n,q);
for i:=2 to m+1 do
for s:=2 to n+1 do
read(a[i,s]);
for i:=1 to q do
begin
c:=0;
read(ex,ey,sx,sy,tx,ty);
if a[tx,ty]=0 then  t:=-1;
if a[tx+1,ty]=0 then c:=c+1;
if a[tx-1,ty]=0 then c:=c+1;
if a[tx,ty+1]=0 then c:=c+1;
if a[tx,ty-1]=0 then c:=c+1;
if a[sx+1,sy]=0 then b:=b+1;
if a[sx-1,sy]=0 then b:=b+1;
if a[sx,sy+1]=0 then b:=b+1;
if a[sx,sy-1]=0 then b:=b+1;
if (c<3) and (t<>-1)and(b<3)
then
begin
s:=(abs(ex-sx)+abs(ey-sy))+(abs(sx-tx)+abs(sy-ty))-1;
write(s);
end
else  if (ex=tx)and(ey=ty)and((abs(sx-tx)=1)or(abs(sy-ty)=1)) then write(1)
else write(-1);
close(input);
close(output);

end;
end.