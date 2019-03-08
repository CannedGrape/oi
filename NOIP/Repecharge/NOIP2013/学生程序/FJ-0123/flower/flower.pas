var a:array[0..100011] of longint;
    n,i,ans,temp,tot:longint;
begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  if n=0 then begin writeln(0);halt;end;
  for i:=1 to n do
  read(a[i]);
  temp:=1;
  i:=1;
  while i<=n do
  begin
    if temp=1 then
    begin
      inc(tot);
      while (a[i]<=a[i+1])and(i<=n) do inc(i);
      inc(i);
      temp:=0;
    end
    else
    begin
      inc(tot);
      while (a[i]>=a[i+1])and(i<=n) do inc(i);
      inc(i);
      temp:=1;
    end;
  end;
  ans:=tot;
  tot:=0;
  temp:=0;
  i:=1;
  while i<=n do
  begin
    if temp=1 then
    begin
      inc(tot);
      while (a[i]<=a[i+1])and(i<=n) do inc(i);
      inc(i);
      temp:=0;
    end
    else
    begin
      inc(tot);
      while (a[i]>=a[i+1])and(i<=n) do inc(i);
      inc(i);
      temp:=1;
    end;
  end;
  if tot>ans then ans:=tot;
  if ans<1 then ans:=1;
  writeln(ans);
  close(input);
  close(output);
end.
