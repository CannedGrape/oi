program flower(input,output);
var
n,i:longint;
h:array[1..100000] of longint;

function pd(a:array of longint;n:longint):longint;
var
i,s,t:longint;
begin
  s:=0;
  t:=trunc(n/2);
  for i:=1 to t do
    if (((a[i*2]>a[i*2+1]) and (a[i*2]>a[i*2-1])) or ((a[i*2]>a[i*2-1]) and (i*2+1>n))) or (((a[i*2]<a[i*2+1]) and (a[i*2]<a[i*2-1])) or ((a[i*2]<a[i*2-1]) and ((i*2+1)>n)))
      then s:=s+1;
  pd:=t-s;
end;

procedure tdel(c:longint);
var
i:longint;
begin
  for i:=c to n-1 do
    h[i]:=h[i+1];
  h[n]:=0;
  dec(n);
end;

procedure fdel(b:array of longint;c,n:longint);
var
i,p1,p2:longint;
begin
  p1:=pd(b,n);
  for i:=c to n-1 do
    b[i]:=b[i+1];
  b[n]:=0;
  dec(n);
  p2:=pd(b,n);
  if p2<p1 then tdel(c);
end;

begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(h[i]);
  while pd(h,n)>0 do
  fdel(h,1,n);
  writeln(n-1);
  close(input);
  close(output);
end.

