program ex;
var a,d1,d2:array[1..100000]of longint;
i,j,k,l,n,m1,m2,ans:longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);
d1[1]:=1; d2[1]:=1;
for i:=2 to n do
begin
m1:=1;m2:=1;
for j:=1 to i-1 do
begin
if ((d1[j]+1) mod 2=0)and(a[j]>a[i])and(d1[j]+1>m1)then m1:=d1[j]+1;
if ((d1[j]+1) mod 2=1)and(a[j]<a[i])and(d1[j]+1>m1)then m1:=d1[j]+1;
if ((d2[j]+1) mod 2=0)and(a[j]<a[i])and(d2[j]+1>m2)then m2:=d2[j]+1;
if ((d2[j]+1) mod 2=1)and(a[j]>a[i])and(d2[j]+1>m2)then m2:=d2[j]+1;
end;
d1[i]:=m1;d2[i]:=m2;
if m1>ans then ans:=m1;
if m2>ans then ans:=m2;
end;
writeln(ans);
close(input);
close(output);
end.
