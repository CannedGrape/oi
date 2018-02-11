var
  a:array[0..100100] of longint;
  i,n,m,t,ac:longint;

begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  read(n);
  for i:= 1 to n do read(a[i]);

  m:=1; t:=a[1];
  for i:= 2 to n do
  begin
    if m and 1=1 then
      begin if a[i]>t then inc(m); end
    else
      if a[i]<t then inc(m);
    t:=a[i];
  end;

  ac:=m;

  m:=1; t:=a[1];
  for i:= 2 to n do
  begin
    if m and 1=0 then
      begin if a[i]>t then inc(m); end
    else
      if a[i]<t then inc(m);
    t:=a[i];
  end;

  if m>ac then ac:=m;
  write(ac);
  close(input); close(output);
end.
