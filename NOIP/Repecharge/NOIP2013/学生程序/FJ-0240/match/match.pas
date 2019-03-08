program match;
type ar=array[1..100000] of integer;
var
f1,f2:text;
a,b:ar;
n,s,i:longint;
procedure kpai(r:ar;l,p:longint;var s:longint);
var
i,j,mid,tmp:longint;
begin
i:=l;j:=p;mid:=a[(l+p)div 2];
repeat
while r[i]<mid do inc(i);
while r[j]>mid do dec(j);
if i<=j then
begin tmp:=r[i];r[i]:=r[j];r[j]:=tmp;inc(s); end;
until i>j;
if i<p then kpai(r,i,p,s);
if j>l then kpai(r,l,j,s);
end;
begin
assign(f1,'match.in');reset(f1);
assign(f2,'match.out');reset(f2);
readln(n);
for i:=1 to n-1 do read(a[i]);readlna[n];
for i :=1 to n do read(b[i]);
kpai(a,1 n,s);kpai(b,1,n,s);s:=0;
writeln(s);
close(f1);close(f2);
end.