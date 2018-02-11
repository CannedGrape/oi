uses math;
var a,b:array[1..10000000]of longint;
v:array[1..3000,1..3000]of longint;
 i,j,r,x,y,z,m,n,ch,q,ka,kb:longint;
procedure new(x,y,z:longint);
var i,j,ri:longint;
begin
if v[x,y]<z then
begin
v[x,y]:=z; r:=r+1;ri:=r; a[r]:=x; b[r]:=y;
for j:=1 to ri-1 do
if(b[j]=a[ri])and(a[j]<>b[ri])then
new(a[j],b[ri],min(v[x,y],v[a[j],b[j]]));
for j:=1 to ri-1 do
if(a[j]=b[ri])and(a[ri]<>b[j])then
new(a[ri],b[j],min(v[x,y],v[a[j],b[j]]));

end;
end;


begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
readln(n,m);
for i:=1 to m do begin
readln(x,y,z); if x>y then begin ch:=x; x:=y; y:=ch; end;
new(x,y,z); end;

readln(q);
for i:=1 to q do
begin
readln(ka,kb);
if ka>kb then begin ch:=ka; ka:=kb; kb:=ch;end;
if v[ka,kb]=0 then writeln(-1)
else writeln(v[ka,kb]);
end;
close(input);
close(output);


end.
