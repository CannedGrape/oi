var a,f,s:array [0..1200000] of longint;
    n,p,i,j,t,ma:longint;
    fo:text;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  t:=0;
  ma:=a[1];
  for i:=1 to n do
  begin
    inc(t,a[i]);
    if t<0 then t:=0;
    if t>ma then ma:=t;
    f[i]:=ma;
  end;
  s[1]:=f[1];ma:=s[1]+f[1];
  for i:=2 to n do
  begin
    if (f[i-1]+s[i-1])>ma then ma:=f[i-1]+s[i-1];
    s[i]:=ma;
  end;
  ma:=s[1];
  for i:=1 to n do if s[i]>ma then ma:=s[i];
  if ma>=0 then writeln(ma mod p)
  else writeln('-',abs(ma) mod p);
  close(output);
  close(input);
end.