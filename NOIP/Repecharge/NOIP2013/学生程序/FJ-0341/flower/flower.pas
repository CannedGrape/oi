program flower;
var f:array[1..100000,1..2] of longint;
    a:array[1..100000] of longint;
    n,i,j,o:longint;
function max(a,b:longint):longint;
begin
if a>b then max:=a else max:=b;
end;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);
fillchar(f,sizeof(f),0);
f[n,1]:=1;
f[n,2]:=1;
for i:= n-1 downto 1 do
 for j:=n downto i+1 do
  begin
  if a[i]>a[j] then
      f[i,2]:=max(f[i,2],f[j,1]+1);
   if a[i]<a[j] then
      f[i,1]:=max(f[i,1],f[j,2]+1);
  end;
for i:=1 to n do if o<max(f[i,1],f[i,2]) then o:=max(f[i,1],f[i,2]);
if o mod 2=0 then o:=o-1;
write(o);
close(input);
close(output);
end.