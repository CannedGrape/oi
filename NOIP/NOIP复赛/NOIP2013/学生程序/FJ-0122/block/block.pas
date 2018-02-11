var
  h:array[0..100001]of longint;
  b:array[0..100001]of boolean;
  bo:array[0..10000]of boolean;
  d:array[0..10000]of longint;
  n,i,j,k,m,mm:longint;
  t:int64;
procedure kp(l,r:longint);
var
  i,j,mid,t:longint;
begin
  i:=l;j:=r;
  mid:=d[(l+r)div 2];
  repeat
    while d[i]<mid do inc(i);
    while d[j]>mid do dec(j);
    if i<=j then
    begin
      t:=d[i];d[i]:=d[j];d[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);mm:=-1;
  for i:=1 to n do
  begin
    read(h[i]);
    if h[i]>mm then mm:=h[i];
    if bo[h[i]] then continue
    else
    begin
      bo[h[i]]:=true;
      inc(m);
      d[m]:=h[i];
    end;
  end;
  if n<=5000 then
  begin
    kp(1,m);
    for i:=1 to m do
    begin
      j:=1;
      while j<=n do
      begin
        if not b[j] then
        begin
          inc(t);
           while (not b[j])and(j<=n) do inc(j);
        end;
        while (b[j])and(j<=n) do inc(j);
      end;
      for j:=1 to n do
        if h[j]=d[i] then b[j]:=true;
    end;
    writeln(t);
  end
  else
  begin
    for i:=1 to mm do
    begin
      j:=1;
      while j<=n do
      begin
        if not b[j] then
        begin
          inc(t);
           while (not b[j])and(j<=n) do inc(j);
        end;
        while (b[j])and(j<=n) do inc(j);
      end;
      for j:=1 to n do
        if h[j]=i then b[j]:=true;
    end;
    writeln(t);
  end;
  close(input);close(output);
end.