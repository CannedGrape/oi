var
a,b,x:array[1..1000]of longint;
n,p,j,i,max:longint;
begin
assign(input,'number.in');
reset(input);
assign(output,'number.out');
rewrite(output);
read(n,p);
for i:=1 to n do read(a[i]);
while a[i]<0 do i:=i+1;
for j:=i to n do x[j]:=a[j]+x[j-1];
b[1]:=1;
x[1]:=1;
for i:=2 to n do b[i]:=b[i-1]+x[i-1];
max:=-maxlongint;
for i:=1 to n do if b[i]>max then max:=b[i];
if max<0 then write('-');
max:=abs(max);
max:=max mod p ;
write(max);
close(input);
close(output);
end.
