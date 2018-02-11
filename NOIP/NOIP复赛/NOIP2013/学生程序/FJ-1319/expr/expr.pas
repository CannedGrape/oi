program r4;
var s:ansistring;w,v,z:integer;c,n:array[1..4] of integer;
b:array[1..1000] of char;a:array[1..10000] of integer;
f1,f2:text;   x:char; k,i,j,l,e:longint;d:array[0..100] of longint;
begin
assign(f1,'expr.in');
assign(f2,'expr.out');
reset(f1);
rewrite(f2);
readln(f1,s);
w:=1;
e:=length(s);
for i:=1 to e do
 begin
if (s[i]='+') or (s[i]='*') then
begin
b[w]:=s[i];
d[w]:=i;
w:=w+1;
end else
a[i]:=ord(s[i])-48;   end;
 k:=1;
while k<=w do
begin
j:=1;
if b[k]='+' then
for i:=d[k-1]+1 to d[k]-1 do
begin
c[j]:=c[j]+a[i]+v;
v:=c[j] mod 10;
if  c[j]>9 then
c[j]:=c[j] div 10;
j:=j+1;
end;
k:=k+1;
end;   v:=4;
for i:=4 downto 2 do
if c[i]=0 then v:=v-1
else break;
for i:=1 downto v do write(f2,c[i]);
close(f1);
close(f2);
end.




