var
  n,p,i,j,max,mmax,mmmax:longint;
  a,f,x:array[0..1000000]of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  max:=-maxlongint;
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    for j:=1 to i do
      if f[i]+a[j]<a[j] then f[i]:=a[j] else f[i]:=(f[i]+a[j])mod p;
  x[1]:=f[1];
  max:=x[1];
  for i:=2 to n do
    begin
      x[i]:=-maxlongint;
      for j:=1 to i-1 do
        if x[i]<x[j]+f[j] then x[i]:=(x[j]+f[j])mod p;
      if x[i]>max then max:=x[i];
    end;
  writeln(max);
  close(input);
  close(output);
end.
