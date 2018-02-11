program ex1 ;
const w:array[1..4,1..2]of longint=((1,0),(-1,0),(0,1),(0,-1));
var a,c:array[1..30,1..30]of longint;
d:array[1..900,1..2]of longint;
bo:boolean;
i,j,k,l,n,m,ex,ey,sx,sy,tx,ty,head,tail,ans,t:longint;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
readln(n,m,k);
for i:=1 to n do
for j:=1 to m do
read(a[i,j]);
for l:=1 to k do
begin
fillchar(c,sizeof(c),0);
bo:=false;
read(ex,ey,sx,sy,tx,ty);
j:=0; t:=a[ex,ey];
a[ex,ey]:=1;
for i:=1 to 4 do
if (tx+w[i,1]<1)or(tx+w[i,1]>n)or(ty+w[i,2]<1)or(ty+w[i,2]>m)
or(a[tx+w[i,1],ty+w[i,2]]=0) then inc(j);
if j>=3 then writeln(-1)
else begin
d[1,1]:=ex;d[1,2]:=ey;
head:=0;tail:=1;
repeat
inc(head);
for i:=1 to 4 do
if (d[head,1]+w[i,1]>=1)and(d[head,1]+w[i,1]<=n)and(d[head,2]+w[i,2]>=1)and(d[head,2]+w[i,2]<=m)
and(a[d[head,1]+w[i,1],d[head,2]+w[i,2]]=1)and(c[d[head,1]+w[i,1],d[head,2]+w[i,2]]=0)
then begin
inc(tail);
d[tail,1]:=d[head,1]+w[i,1];
d[tail,2]:=d[head,2]+w[i,2];
c[d[head,1]+w[i,1],d[head,2]+w[i,2]]:=c[d[head,1],d[head,2]]+1;
if (d[tail,1]=tx)and(d[tail,2]=ty) then begin bo:=true;break;end;
end;
if bo then break;
until head>tail;
if bo=false then writeln(-1)
else begin
ans:=c[tx,ty];
fillchar(c,sizeof(c),0);
bo:=false;
d[1,1]:=tx;d[1,2]:=ty;
head:=0;tail:=1;
repeat
inc(head);
for i:=1 to 4 do
if (d[head,1]+w[i,1]>=1)and(d[head,1]+w[i,1]<=n)and(d[head,2]+w[i,2]>=1)and(d[head,2]+w[i,2]<=m)
and(a[d[head,1]+w[i,1],d[head,2]+w[i,2]]=1)and(c[d[head,1]+w[i,1],d[head,2]+w[i,2]]=0)
then begin
inc(tail);
d[tail,1]:=d[head,1]+w[i,1];
d[tail,2]:=d[head,2]+w[i,2];
c[d[head,1]+w[i,1],d[head,2]+w[i,2]]:=c[d[head,1],d[head,2]]+1;
if (d[tail,1]=sx)and(d[tail,2]=sy) then begin bo:=true;break;end;
end;if bo then break;
until head>tail;
if bo=false then writeln(-1)
else writeln(ans+c[sx,sy]);
end;
end;
a[ex,ey]:=t;
end;
close(input);
close(output);
end.