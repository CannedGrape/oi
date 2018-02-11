program exam1;
var f,k,mmax:array[0..1000000] of int64;
    a:array[0..1000000] of int64;
    i,n:longint;
    p,max:int64;
function max1(a,b:int64):int64;
begin
  if a>b then max1:=a
  else max1:=b;
end;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  read(n,p);
  for i:=1 to n do
  read(a[i]);
  max:=-maxlongint;
  f[1]:=a[1];
  for i:=2 to n do
  f[i]:=max1(a[i] mod p,max1(f[i-1]+a[i] mod p,f[i-1] mod p));
  k[1]:=f[1];
  mmax[1]:=k[1];
  mmax[2]:=k[1]+f[1];
  k[2]:=mmax[2];
  for i:=3 to n do
  begin
  mmax[i]:=max1(mmax[i-1] mod p,k[i-1]+f[i-1] mod p);
  k[i]:=mmax[i];
  end;
  for i:=1 to n do
  if mmax[i] mod p>max  then max:=mmax[i] mod p;
  writeln(max);
  close(input);
  close(output);
end.

