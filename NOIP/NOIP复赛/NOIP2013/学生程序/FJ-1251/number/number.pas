var t,f,a:array[1..1000000]of longint;
    n,p,i,max,max1:longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  t[1]:=a[1];
  for i:=2 to n do
  begin
    t[i]:=t[i-1];
    if a[i]>0 then
    begin
      if (t[i]<0)and(a[i]>t[i]) then t[i]:=a[i]
      else if t[i]>0 then t[i]:=t[i]+a[i];
    end
    else begin
    if (t[i]<0)and(a[i]>t[i]) then t[i]:=a[i];
    end;
  end;
  f[1]:=a[1]*2;max:=t[1];f[2]:=f[1];
  for i:=3 to n do
  begin
    f[i]:=f[i-1];
    if t[i-1]+f[i-1]>f[i] then f[i]:=t[i-1]+f[i-1];
    if f[i]>max then max:=f[i];
  end;
  if max<0 then
  begin
    max1:=abs(max);
    write('-');
    write(max1 mod p);
  end
  else write(max mod p);
  close(input);
  close(output);
end.
