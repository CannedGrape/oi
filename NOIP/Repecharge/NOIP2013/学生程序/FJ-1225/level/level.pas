var a:array[0..1000] of longint;
    n,m,i,j,t,x,p:longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(t);
    for p:=1 to t do
    begin
      read(x);
      a[i]:=a[i]*10+x;
    end;
    readln;
  end;
  for i:=1 to m do
   for t:=i+1 to m do
   if a[i]=a[t] then inc(j);
  m:=m-j;
  if m=0 then writeln(1)
  else writeln(m);
  close(input);close(output);
end.
