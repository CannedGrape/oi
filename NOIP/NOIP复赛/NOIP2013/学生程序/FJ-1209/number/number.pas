var
  n,p,x,i,max:longint;
  s,t,f:array[1..1000000] of longint;
begin
  assign(input'number.in');
  reset(input);
  assign(output'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
begin
  read(s[i]);
  t[i]:=t[i-1]+s[i];
end;
  f[1]:=t[1];
  max:=-maxlongint;
  for i:=2 to n do
  f[i]:=f[i-1]+t[i-1];
  for i:=1 to n do
begin
  if f[i]>=max then max:=f[i];
end;
  write(max mod p);
  close(input);
  close(output);
end.



























