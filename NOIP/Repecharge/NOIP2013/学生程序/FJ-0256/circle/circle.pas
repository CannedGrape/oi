var
  n,m,k,x,i,s,t:longint;
  a:array [1..100] of longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  close(input);
  while k<>1 do
  begin
    inc(t);
    a[t]:=k mod 2;
    k:=k div 2;
  end;
  s:=10 mod n;
  for i:=t downto 1 do
  begin
    s:=s*s mod n;
    if a[i]=1 then s:=(s*(10 mod n))mod n;
  end;
  for i:=1 to s do
  begin
    x:=x+m;
    if x>=n then x:=x mod n;
  end;
  write(x);
  close(output);
end.
