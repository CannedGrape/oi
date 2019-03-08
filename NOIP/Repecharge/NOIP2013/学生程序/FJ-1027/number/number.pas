program number;
var
  n,p,i,j,max:longint;
  a,f1,f2:array[1..1000000]of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  readln;
  f1[1]:=a[1];
  for i:=2 to n do
    if f1[i-1]>f1[i-1]+a[i] then f1[i]:=f1[i-1] else f1[i]:=f1[i-1]+a[i];
  f2[1]:=f1[1];
  f2[2]:=f1[1]+f2[1];
  for i:=3 to n do
    if f2[i-1]>f1[i-1]+f2[i-1] then f2[i]:=f2[i-1] mod p
    else f2[i]:=(f1[i-1]+f2[i-1]) mod p;
  max:=-maxlongint;
  for i:=1 to n do
  if f2[i]>max then max:=f2[i];
  max:=max mod p;
  writeln(max);
  close(input);
  close(output);
end.