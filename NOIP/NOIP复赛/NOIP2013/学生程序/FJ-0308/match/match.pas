program match;
  var n:longint;
      i,j:longint;
      a,b:array[1..100000] of int64;
      c,d:array[1..100000] of longint;
      count:longint;
  procedure qsorta(p,q:longint);
    var t,m:int64;
        l,r:longint;
  begin
    l:=p;r:=q;
    m:=a[(p+q) div 2];
    repeat
      while a[l]<m do inc(l);
      while a[r]>m do dec(r);
      if l<=r then
        begin
          t:=a[l];
          a[l]:=a[r];
          a[r]:=t;
          t:=c[l];
          c[l]:=c[r];
          c[r]:=t;
          inc(l);
          dec(r);
        end;
    until l>r;
    if l<q then qsorta(l,q);
    if r>p then qsorta(p,r);
  end;
  procedure qsortb(p,q:longint);
    var t,m:int64;
        l,r:longint;
  begin
    l:=p;r:=q;
    m:=b[(p+q) div 2];
    repeat
      while b[l]<m do inc(l);
      while b[r]>m do dec(r);
      if l<=r then
        begin
          t:=b[l];
          b[l]:=b[r];
          b[r]:=t;
          t:=d[l];
          d[l]:=d[r];
          d[r]:=t;
          inc(l);
          dec(r);
        end;
    until l>r;
    if l<q then qsortb(l,q);
    if r>p then qsortb(p,r);
  end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  count:=0;
  for i:=1 to n do
    begin c[i]:=i;d[i]:=i;end;
  for i:=1 to n do    read(a[i]);
  readln;
  for i:=1 to n do    read(b[i]);
  qsorta(1,n);qsortb(1,n);
  for i:=1 to n-1 do
    if c[i]<>d[i] then
      begin
        count:=count+1;
        for j:=i to n do
          if c[j]=d[i] then begin c[j]:=c[i];break;end;
      end;
  write(count);
  close(input);close(output);
end.














