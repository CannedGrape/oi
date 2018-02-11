var
  n,i,s,x:longint;
  a:array [1..100000] of longint;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  close(input);
  s:=a[1];
  x:=a[1];
  for i:=2 to n do
  begin
    if a[i]>x then s:=s+a[i]-x;
    x:=a[i];
  end;
  write(s);
  close(output);
end.
