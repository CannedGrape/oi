program block;
var
  a:array[0..100001] of longint;
  i,j,k,n,m,s,t,x,y,q,p:longint;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  m:=n;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]=0 then dec(m);
  end;
  t:=0;
  while m>0 do
  begin
    x:=0;
    y:=0;
    s:=0;
    while y<n do
    begin
      if n-x+1<s then break;
      while (a[y]=0) and (y<=n) do inc(y);
      x:=y;
      q:=maxlongint;
      while a[y]>0 do
      begin
        if (a[y]<q) and (a[y]>0) then q:=a[y];
        inc(y);
      end;
      if y-x>s then
      begin
        s:=y-x;
        i:=x;
        j:=y-1;
        p:=q;
      end;
    end;
    for k:=i to j do
    begin
      a[k]:=a[k]-p;
      if a[k]=0 then dec(m);
    end;
    t:=t+p;
  end;
  write(t);
  close(input);
  close(output);
end.
