var
  n,p,i,j,x:longint;
  a,c,s:array[1..10000000]of longint;
function tz(t:longint):longint;
begin
  for i:=1 to t do
  s[i]:=0;
  for i:=1 to t do
  begin
  for j:=i to t do
  s[i]:=s[i]+a[j];
  end;
  tz:=s[i];
  for i:=1 to t do
  if s[i]>tz then tz:=s[i];
end;
function fs(t:longint):longint;
begin
  fs:=0;
  for i:=1 to n do
  s[i]:=0;
  if t=1 then fs:=tz(t) else
  begin
  for i:=1 to t-1 do
  s[i]:=s[i]+fs(i)+tz(i);
  fs:=s[1];
  for i:=1 to t do
  if s[i]>fs then fs:=s[i];
  end;
end;
begin
  assign(input);
  reset(input,'number.in');
  assign(output);
  rewrite(output,'number.out');
  readln(n,p);
  for i:=1 to n do
  read(a[i]);
  for i:=1 to n do
  c[i]:=fs(i);
  x:=c[i];
  for i:=2 to n do
  if c[i]>x then x:=c[i];
  writeln((x-1) mod p);
  close(input);
  close(output);
  readln;readln;
end.
