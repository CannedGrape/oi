var
n,i,j,max1,max2,jmax,omax:longint;
a:array[0..100000] of longint;
ji,ou:array[0..100000] of longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
read(n);
for i:= 1 to n do read(a[i]);
for i:= 1 to n do
begin
jmax:=0;
omax:=0;
for j:=1 to i-1 do if (ji[j]>jmax) and (a[j]>a[i]) then jmax:=ji[j];
for j:=1 to i-1 do if (ou[j]>omax) and (a[j]<a[i]) then omax:=ou[j];
if jmax>0 then
ou[i]:=jmax+1;
ji[i]:=omax+1;




end;
max1:=0;
for i:= n downto 1 do
begin
if ou[i]>max1 then max1:=ou[i];
if ji[i]>max1 then max1:=ji[i];
end;



fillchar(ji,sizeof(ji),0);
fillchar(ou,sizeof(ou),0);

for i:= 1 to n do
begin
jmax:=0;
omax:=0;
for j:=1 to i-1 do if (ji[j]>jmax) and (a[j]<a[i]) then jmax:=ji[j];
for j:=1 to i-1 do if (ou[j]>omax) and (a[j]>a[i]) then omax:=ou[j];
if jmax>0 then
ou[i]:=jmax+1;
ji[i]:=omax+1;




end;
max2:=0;
for i:= n downto 1 do
begin
if ou[i]>max2 then max2:=ou[i];
if ji[i]>max2 then max2:=ji[i];
end;
if max1>max2 then write(max1) else write(max2);


close(input);
close(output);






end.
