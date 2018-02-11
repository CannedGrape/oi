program ex;
var a,b,a1,b1,c1,c2:array[1..100000]of longint;
i,j,k,l,n,m,s,t,ans:longint;

procedure qsort2(l,r:longint);
var i,j,t,mid:longint;
begin
i:=l;j:=r;mid:=b[(l+r)div 2];
repeat
while (i<r)and(b[i]<mid)do inc(i);
while (j>l)and(b[j]>mid)do dec(j);
if i<=j then
begin
t:=b[i];b[i]:=b[j];b[j]:=t;
t:=c2[i];c2[i]:=c2[j];c2[j]:=t;
inc(i);dec(j);
end;
until i>j ;
if i<r then qsort2(i,r);
if l<j then qsort2(l,j);
end;


procedure qsort1(l,r:longint);
var i,j,t,mid:longint;
begin
i:=l;j:=r;mid:=a[(l+r)div 2];
repeat
while (i<r)and(a[i]<mid)do inc(i);
while (j>l)and(a[j]>mid)do dec(j);
if i<=j then
begin
t:=a[i];a[i]:=a[j];a[j]:=t;
t:=c1[i];c1[i]:=c1[j];c1[j]:=t;
inc(i);dec(j);
end;
until i>j ;
if i<r then qsort1(i,r);
if l<j then qsort1(l,j);
end;


begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
readln(n);
for i:=1 to n do
begin
read(a[i]);
a1[i]:=a[i];
c1[i]:=i;
end;
for i:=1 to n do
begin
read(b[i]);
b1[i]:=b[i];
c2[i]:=i;
end;
qsort1(1,n);
qsort2(1,n);
ans:=0;
for i:=1 to n do
ans:=(ans+abs(c1[i]-c2[i])mod 99999997)mod 99999997;
writeln(ans div 2);
close(input);
close(output);
end.
