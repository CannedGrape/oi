program circle;
var
  a:array[0..1000001] of longint;
  b:array[0..1000001] of longint;
  i,j,k,n,m,t,x,y:longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  read(n,m,k,x);
  if x=0 then x:=n;
  a[0]:=x;
  i:=1;
  repeat
    a[i]:=a[i-1]+m;
    if a[i]>n then a[i]:=a[i]-n;
    inc(i);
  until a[i-1]=a[0];
  dec(i);
  if 1000000000 mod i=0 then
  begin
    if a[i]=n then write('0')
    else write(a[i]);
  end
  else
  begin
    t:=1;
    j:=0;
    y:=1;
    while y<i do
    begin
      y:=y*10;
      inc(j);
    end;
    b[t]:=y mod i;
    repeat
      y:=b[t];
      inc(t);
      while y<i do
      begin
        y:=y*10;
        inc(j);
        if j=k then break;
      end;
      if y>=i then b[t]:=y mod i;
    until (b[t]=b[1]) or (j=k);
    dec(t);
    if b[t]<>b[1] then write(a[b[t]+y])
    else
    begin
      if k>t then
      if (t>1) and (k mod t<>0) then k:=k mod t
      else k:=t;
      if a[b[k]]=n then write('0')
      else write(a[b[k]]);
    end;
  end;
  close(input);
  close(output);
end.
