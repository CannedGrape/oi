program nai;
var i,n,m,x,y,q,z,max:longint; link,tlink:array[0..10000,0..10000]of boolean;
limit,min:array[0..10000,0..10000]of longint;flag:boolean;
bi:array[0..10000]of boolean;
{procedure go(k:longiont);
var t:longint;
begin
for t:=1 to n do
if link[k,t]=true then
}
function min2(a,b:longint):longint;
begin
if a<b then exit(a) else exit(b);
end;
function go(k:longint):longint;
var t:longint;
begin
if k=y then begin go:=maxlongint; flag:=true; exit; end
else
for t:=1 to n do
if (tlink[k,t]=true) and (bi[t]) then
begin
tlink[k,t]:=false;
tlink[t,k]:=false;
bi[t]:=false;
min[k,t]:=min2(go(t),limit[k,t]);
end;
for t:=1 to n do
if (link[k,t])  and (max<min[k,t]) then
max:=min[k,t];
if flag then go:=max else go:=-1;
end;



begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);
readln(n,m);
for i:=1 to m do
begin
readln(x,y,z);
link[x,y]:=true;
limit[x,y]:=z;
link[y,x]:=true;
limit[y,x]:=z;
end;
readln(q);
for i:=1 to q do
begin
fillchar(bi,sizeof(bi),true);
flag:=false;
tlink:=link;
readln(x,y);
writeln(go(x));{
write(min[1,3]);
write(go(3));}
end;
close(input);
close(output);

end.
