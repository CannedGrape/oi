program number;
var a:array[1..1000000] of longint;
    n,j,i,pp,p:longint;
function max(i,j:longint):longint;
begin
  if i>j then max:=i
   else max:=j;
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  for i:=1 to n do
   read(a[i]);
  for i:=n downto 1 do
  begin
   for j:=1 to i-1 do
   a[i]:=a[i]+a[j];
  end;
  pp:=a[n-1];
  for i:=3 to n+1 do
     a[i]:=max(a[i-2]+a[i-1],a[i-2]);
  a[n]:=max(a[n],a[n]+pp);
  if a[n]>=0 then p:=a[n]
  else p:=-a[n];
  write(a[n]);
  close(input);
  close(output);
end.

