var n,m,k,x,g,t,r,i:longint;
    a:array[0..1000000]of longint;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  g:=k; t:=0;
  while g<>0 do
  begin
    inc(t);
    a[t]:=g mod 2;
    g:=g div 2;
  end;
  r:=1;
  for i:=t downto 1 do
  begin
    k:=(r*r) mod n;
    if a[i]<>0 then r:=((10*k)mod n)mod n
               else r:=k;
  end;
  for i:=1 to r do
  x:=(x+m)mod n;
  writeln(x);
  close(input); close(output);
end.