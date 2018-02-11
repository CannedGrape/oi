program number;
var
  a:array[1..6,1..2000000]of longint;
  n,p,i,j,k,max1:longint;
procedure init;
begin
  readln(n,p);
  for i:=1 to n do
    read(a[1,i]);
end;
procedure make;
var
  max:longint;
begin

  for i:=1 to n do
    for j:=1 to i do
      a[2,i]:=a[1,j]+a[2,i];
  a[3,1]:=a[2,1];
  for i:=2 to n do
  begin
    max:=-maxlongint;
    for k:=1 to i-1 do
      if a[2,k]+a[3,k]>max then max:=a[2,k]+a[3,k];
    a[3,i]:=max;
  end;
end;

begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  init;
  make;
  max1:=-maxlongint;
  for i:=1 to n do
    if a[3,i]>max1 then max1:=a[3,i];
  write(max1 mod p);
  close(input);
  close(output);
end.




