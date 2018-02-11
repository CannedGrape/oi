type
rec=record
y:longint;
q:longint;
end;

var
l:array[0..10000,1..800] of rec;
can:array[0..10000] of 0..1;
t:array[0..10000] of 0..500;
dis:array[0..10000] of longint;
n,m,q,i,x,y,z,k:longint;
flag:boolean;



function min(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);

end;




procedure spfa(k:longint);
var i,mm:longint;
begin
can[k]:=0;
for i:= 1 to t[k] do
begin
mm:=min(dis[k],l[k,i].q);
if dis[l[k,i].y]<mm then
begin
dis[l[k,i].y]:=mm;
can[l[k,i].y]:=1;
flag:=true;

end;
end;
end;

begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
read(n,m);
for i:= 1 to m do
begin
read(x,y,z);
inc(t[x]);
l[x,t[x]].y:=y;
l[x,t[x]].q:=z;
inc(t[y]);
l[y,t[y]].y:=x;
l[y,t[y]].q:=z;
end;
read(q);
for k:= 1 to q do
begin
read(x,y);
fillchar(dis,sizeof(dis),0);
fillchar(can,sizeof(can),0);
can[x]:=1;
dis[x]:=maxlongint;
flag:=true;
while flag do
begin
flag:=false;
for i:= 1 to n do if can[i]=1 then spfa(i);





end;
if dis[y]=0 then writeln(-1) else
writeln(dis[y]);








end;








close(input);
close(output);

end.


