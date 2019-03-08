var
  n,c,x,s,i:longint;
  a:array [1..100000] of longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  read(n);
  s:=1;
  for i:=1 to n do
  begin
    read(a[i]);
    if (i<>1)and(a[i]<>a[i-1]) then
    begin
      if a[i]>a[i-1] then x:=3 else x:=2;
      if x<>c then inc(s);
      c:=x;
    end;
  end;
  write(s);
  close(input);
  close(output);
end.
