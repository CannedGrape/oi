var  a:array[0..100001]of longint;
     i,n,t,k,ac1,ac2,tt:longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n);
  tt:=0;
  for i:=1 to n do begin read(a[i]); if a[i]<>tt then tt:=a[i]; end;
  if tt=a[1] then writeln(1)
  else
  begin
  ac1:=1; t:=1;
  while (a[t+1]>=a[t]) and (t<=n) do inc(t);
  if t>1 then inc(ac1);
   while t<=n do
    begin
      k:=t;
      while (a[t+1]<=a[t]) and(t<n) do inc(t);
      if k=t then break;
      if (t<=n) then inc(ac1);
      k:=t;
      while (a[t+1]>=a[t]) and (t<n) do inc(t);
      if k=t then break;
      if (t<=n) then inc(ac1);
    end;
  ac2:=1; t:=1;
  while (a[t+1]<=a[t]) and (t<=n) do inc(t);
  if t>1 then inc(ac2);
  while t<=n do
    begin
     k:=t;
      while (a[t+1]>=a[t]) and(t<=n) do inc(t);
      if k=t then break;
      if (t<=n) then inc(ac2);
      k:=t;
     while (a[t+1]<=a[t]) and (t<=n) do inc(t);
     if k=t then break;
      if (t<=n) then inc(ac2);
    end;
    if ac1>ac2 then write(ac1)
     else write(ac2);
  end;
close(input);
close(output);
end.
