program number;
var
  a,b,c,d:array[0..1500000] of int64;
  j,k,m,n,s,t:int64;
  i:longint;

function max(a,b:int64):int64;
begin
  if a>b then exit(a) else exit(b);
end;

function mo(a:int64):int64;
begin
  if a<0 then
  begin
    mo:=abs(a) mod m*-1;
  end else mo:=a mod m;
end;

begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to n do
    read(a[i]);
  d[1]:=a[1];
  for i:=2 to n do
    d[i]:=max(a[i],d[i-1]+a[i]);
  t:=-maxlongint;
  for i:=1 to n do
  begin
    if d[i]>t then t:=d[i];
    b[i]:=t;
  end;
  c[1]:=b[1];
  s:=-maxlongint;
  t:=s;
  for i:=2 to n do
  begin
    if c[i-1]>s then s:=c[i-1];
    k:=b[i-1]+c[i-1];
    if k>t then t:=k;
    c[i]:=t;
  end;
  if c[n]>s then s:=c[n];
  writeln(mo(s));
  close(input);
  close(output);
end.