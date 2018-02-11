var
  a:array[1..1000000]of longint;
  n,i,t:longint;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  t:=a[1];
  for i:=2 to n do
      if a[i]>a[i-1] then t:=t+a[i]-a[i-1];
  writeln(t);
  close(input);
  close(output);
end.
