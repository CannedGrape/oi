var
  n,max,i,total,x:longint;
  h,g:array[1..100000] of longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  max:=-maxlongint;
  for i:=1 to n do
    read(h[i]);
    for i:=1 to n do
    begin
    dec(h[i]);
    g[i]:=h[i];
    for x:=1 to h[i] do
     if (g[2*x]<g[2*x-1]) and (g[2*x]<g[2*x+1]) and (x>=1) and (x<=g[x] div 2)
        or (g[2*x]>g[2*x-1]) and (g[2*x]>g[2*x+1]) and (x>=1) and (x<=g[x] div 2)
        then inc(g[x]);
    end;
      if g[x]>max then max:=g[x];
    writeln(max);
  close(input);close(output);
end.
