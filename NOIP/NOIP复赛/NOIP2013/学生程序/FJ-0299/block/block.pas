var
  n,i,c:longint;
  g,h:array[1..100000] of longint;
procedure try(x,y:longint);
var r,t,w:longint;
begin
  r:=x;
  repeat
    while (g[r]+1>h[r])and(r<=y) do inc(r);
    if r>y then exit;
    t:=r;
    while (g[r]+1<=h[r])and(r<=y) do
      begin
        inc(r); inc(g[r-1]);
      end;
    w:=r-1;
    //for v:=t to w do inc(g[v]);
    inc(c);
    try(t,w);
  until r>=y;
end;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      read(h[i]);
      g[i]:=0;
    end;
  try(1,n);
  write(c);
  close(input);close(output);
end.
