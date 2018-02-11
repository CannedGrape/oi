var
  n,p,i,j,k,max:longint;
  s:array[1..1000000]of longint;
  t:array[1..1000000]of longint;
  t1:array[1..1000000]of longint;
  f:array[1..1000000]of longint;
  mt:array[1..100000]of longint;
  f1:array[1..100000]of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
  begin
    read(s[i]);
  end;
  readln;
  t[1]:=s[1];
  f[1]:=t[1];
  mt[1]:=t[1];
  for i:=2 to n do
  begin
    mt[i]:=-1000000;
    f[i]:=-1000000;
    for j:=1 to i do
    begin
      t[i]:=t[i]+s[j];
    end;
    for j:=1 to i do
    begin
      t1[i]:=t1[i]+s[j];
      if t1[i]>t[i] then
        if t1[i]>mt[i] then mt[i]:=t1[i];
    end;
    if mt[i]=-1000000 then mt[i]:=t[i];
    for j:=1 to i-1 do
    begin
      f1[j]:=mt[j]+f[j];
      if f1[j]>f[i] then f[i]:=f1[j];
    end;
  end;
  max:=f[1];
  for i:=1 to n do
  begin
    if f[i]>max then max:=f[i];
  end;
  if max<0 then max:=max*-1 mod p;
  if max>=0 then max:=max mod p;
  writeln(max);
  close(input);
  close(output);
end.
