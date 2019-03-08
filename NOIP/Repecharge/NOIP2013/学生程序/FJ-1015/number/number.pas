program a123;
var a,b,c:array[1..1000000] of longint;
    ans,i,j,n,p,min,max:longint;
procedure qsort(l,r:longint);
var i,j,k,mid,temp:longint;
begin
  i:=l;
  j:=r;
  mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while mid<a[j] do dec(j);
    if i<=j then begin
      temp:=a[i];
      a[i]:=a[j];
      a[j]:=temp;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  min:=1;
  readln(n,p);
  for i:=1 to n do
  begin
    read(a[i]);
  end;
  qsort(1,n);
  for i:=1 to n do
  begin
    if a[i]<=0 then begin
      b[i]:=a[i];
      min:=i;
    end;
  end;
  if min<n then begin
    b[min]:=a[min];
    for i:=min+1 to n do
    begin
      b[i]:=b[i-1]+a[i];
    end;
  end;
  c[1]:=b[1];
  for i:=2 to n do
  begin
    max:=-maxlongint;
    for j:=1 to i-1 do
    begin
      if (b[j]+c[j])>max then max:=b[j]+c[j];
    end;
    c[i]:=max;
  end;
  max:=-maxlongint;
  for i:=1 to n do
  begin
    if c[i]>max then max:=c[i];
  end;
  ans:=max mod p;
  write(ans);
  close(input);
  close(output);
end.
