program number;
var
  i,j,k,n,m,z,l,x:longint;
  a,b,c:array[1..1000000]of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
  read(a[i]);
  b[1]:=a[1];
  c[1]:=a[1];
  k:=b[1]+c[1]; x:=a[1];
  for i:=2 to n do
  for l:=1 to i do
  if (a[l]>=0)and(a[l+1]<0)or (a[l]<0)and(a[l+1]>=0)then  begin
    if a[l]>=0 then b[i]:=b[l]+a[l];
  end else begin if a[2]<0 then
  for j:=1 to i do       begin
  if a[j]>x then x:=a[j]; b[i]:=x;x:=0; end else
  begin
  for j:=1 to i do
  x:=x+a[j];b[i]:=x;x:=0;
  end;   end;

  for i:=2 to n do
  for j:=1 to i-1 do
  begin
    if b[j]+c[j]>k then k:=b[j]+c[j];
    c[i]:=k;
  end;
  z:=c[1];
  for i:=2 to n do
  if z<c[i] then z:=c[i];
  writeln(z mod m);
  close(input);
  close(output);
end.
