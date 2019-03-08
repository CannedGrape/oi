program haio;
var n,i,j,t,min,k,ans,x,y:longint;
f:array[0..10000,0..10000]of boolean; a:array[0..100000]of longint;
begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
fillchar(f,sizeof(f),true);
ans:=0;
readln(n);
for i:=1 to n do
begin
read(a[i]);
if a[i]=0 then
begin
for j:=i downto 1 do
for t:=i to n do
f[j,t]:=false;
end;
end;

for i:=n downto 1 do
for j:=1 to (n-i+1) do
if f[j,j+i-1] then
begin   //////////
min:=maxlongint;
for t:=j to (j+i-1) do
if min>a[t] then
  min:=a[t];
ans:=ans+min;
for k:=j to (j+i-1) do
begin
a[k]:=a[k]-min;
if a[k]=0 then
  begin
  for x:=k downto 1 do
  for y:=k to n do
  f[x,y]:=false;
  end;
end;
end;///////////

writeln(ans);
close(input);
close(output);
end.
