var
  d:array[0..101000]of longint;
  h:array[0..101000]of longint;
  n,m,i,j,t,tot:longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  d[1]:=h[1]; t:=1;
  i:=2;
  while i<n do
  begin
    if h[i]<h[i-1] then
    begin
      inc(t);
      while (h[i]<h[i-1])and(i<n) do inc(i);
      d[t]:=h[i-1];
      inc(t);
      d[t]:=h[i];
      inc(i);
    end
    else
    if h[i]>h[i-1] then
    begin
      inc(t);
      while (h[i]>h[i-1])and(i<n) do inc(i);
      d[t]:=h[i-1];
      inc(t);
      d[t]:=h[i];
      inc(i);
    end
    else inc(i);
  end;
  if n mod 2=1 then
    if (h[n]<d[t])and(d[t]>d[t-1]) then inc(t);
  writeln(t);
  close(input);close(output);
end.
