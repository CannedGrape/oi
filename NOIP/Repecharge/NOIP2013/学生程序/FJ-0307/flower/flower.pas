var f,g,a:array[1..100000] of longint;
    i,t,n:longint;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  f[1]:=1; t:=0;
  for i:=2 to n do
   if ((t=0) and (a[i]>a[i-1])) or ((t=1) and (a[i]<a[i-1]))
    then begin f[i]:=f[i-1]+1; t:=1-t; end
    else f[i]:=f[i-1];

  g[1]:=1; t:=1;
  for i:=2 to n do
   if ((t=0) and (a[i]>a[i-1])) or ((t=1) and (a[i]<a[i-1]))
    then begin g[i]:=g[i-1]+1; t:=1-t; end
    else g[i]:=g[i-1];

  if g[n]>f[n] then write(g[n]) else write(f[n]);
  close(input); close(output);
end.
