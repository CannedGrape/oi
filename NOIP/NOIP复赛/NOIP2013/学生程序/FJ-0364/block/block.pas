var n,i,ans:longint;
a,pp:array[1..100000]of integer;
inf,ouf:text;

procedure init;
begin
assign(inf,'block.in');reset(inf);
assign(ouf,'block.out');rewrite(ouf);
read(inf,n);
for i:=1 to n do
read(inf,a[i]);
end;

procedure main(l,r:longint);
var o,p,v,min,max,p1,p2:longint;
begin
o:=l;p:=r;min:=maxlongint;max:=0;

if o=p then begin ans:=ans+a[o];exit;end;

for v:=o to p do
begin
if a[v]>max then max:=a[v];
if a[v]<min then min:=a[v];
end;

if (max=0) then exit;


if min<>0 then
begin
for v:=o to p do
a[v]:=a[v]-min;
ans:=ans+min;
end;

if a[l]=0 then
for v:=l to r do
if a[v]=0 then begin o:=v;break;end;


if a[r]=0 then
for v:=r downto l do
if a[v]=0 then begin p:=v;break;end;


for v:=o to p do
if (a[v]=0) then
begin
p1:=v;
main(o,p1-1);
main(p1+1,p);exit;end;

min:=maxlongint;
for v:=o to p do
if (a[v]<min) then min:=a[v];
if min>0 then main(o,p);

end;

begin
init;
main(1,n);
writeln(ouf,ans);
close(inf);close(ouf);
end.
