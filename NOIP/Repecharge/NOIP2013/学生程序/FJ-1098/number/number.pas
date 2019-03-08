var t,a,f,su:array[1..1000000]of longint;
    max,sum:int64;
    n,p,i,j,k:longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  read(n,p);
  for i:=1 to n do read(a[i]);
  t[1]:=a[1];
  for i:=2 to n do
  begin
    su[i]:=a[i];
    sum:=su[i];
    for j:=i-1 downto 1 do
    begin
      su[j]:=su[j+1]+a[j];
      if su[j]>sum then sum:=su[j];
    end;
    t[i]:=sum;
    if t[i]<t[i-1] then t[i]:=t[i-1];
  end;
  f[1]:=t[1];
  sum:=f[1];
  for i:=2 to n do
  begin
    f[i]:=f[i-1]+t[i-1];
    if f[i]<f[i-1] then f[i]:=f[i-1];
    if f[i]>sum then sum:=f[i];
  end;
  write(sum);
  close(input);
  close(output);
end.