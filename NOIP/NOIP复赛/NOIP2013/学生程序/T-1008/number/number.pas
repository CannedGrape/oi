var
  n,m,max,i,p,j,k,f,mk,jj,min:longint;
  a,b,c,d:array[0..100000]of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(b[i]);   a[1]:=b[1];
  for i:=1 to n do
  a[i]:=b[i]+a[i-1];
  c[1]:=a[1];
  f:=c[1];
  for i:=2 to n do
  begin
  for j:=1 to i do
  begin
  d[j]:=c[j]+a[j];
  if d[j]>f then f:=d[j];
  end;
  c[j]:=f;
  end;
  dec(c[n]);
  max:=c[1];
  for i:=2 to n do
  if c[i]>=max then max:=c[i];
  writeln(max mod p);
  close(input);close(output);
end.

