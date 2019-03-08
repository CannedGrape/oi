program jai;
var n,i,j,max1,max2,temp1,temp2:longint; f1,f2,a:array[0..100000]of longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do
read(a[i]);

if n=1 then begin writeln(1); halt;close(input);close(output); end;
for i:=1 to n do
begin
f1[i]:=1;f2[i]:=1;
end;

for i:=n-1 downto 1 do
begin
temp1:=-maxlongint;temp1:=-maxlongint;
for j:=i+1 to n do
begin
if (a[i]<a[j]) and (temp1<f2[j]) then
temp1:=f2[j];
if (a[i]>a[j]) and (temp2<f1[j]) then
temp2:=f1[j];
end;
f1[i]:=temp1+f1[i];
f2[i]:=temp2+f2[i];
end;

max1:=-maxlongint;
max2:=-maxlongint;
for i:=1 to n do
begin
if f1[i]>max1 then max1:=f1[i];
if f2[i]>max2 then max2:=f2[i];
end;
if max1>max2 then writeln(max1)
else writeln(max2);
close(input);close(output);
end.
