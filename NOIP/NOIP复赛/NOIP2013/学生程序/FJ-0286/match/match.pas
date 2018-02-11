var a,b,c,d:array[0..100000] of longint;
    n,i,s,k:longint;
procedure qsorta(l,r:longint);
var i,j,t,mid:longint;
begin
  i:=l;j:=r;mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      t:=c[i];c[i]:=c[j];c[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsorta(l,j);
  if i<r then qsorta(i,r);
end;
procedure qsortb(l,r:longint);
var i,j,t,mid:longint;
begin
  i:=l;j:=r;mid:=b[(l+r) div 2];
  repeat
    while b[i]<mid do inc(i);
    while b[j]>mid do dec(j);
    if i<=j then
    begin
      t:=b[i];b[i]:=b[j];b[j]:=t;
      t:=d[i];d[i]:=d[j];d[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsortb(l,j);
  if i<r then qsortb(i,r);
end;
procedure qsortc(l,r:longint);
var i,j,t,mid:longint;
begin
  i:=l;j:=r;mid:=c[(l+r) div 2];
  repeat
    while c[i]<mid do inc(i);
    while c[j]>mid do dec(j);
    if i<=j then
    begin
      t:=c[i];c[i]:=c[j];c[j]:=t;
      t:=d[i];d[i]:=d[j];d[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsortc(l,j);
  if i<r then qsortc(i,r);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);c[i]:=i;
  end;
  readln;
  for i:=1 to n do
  begin
    read(b[i]);d[i]:=i;
  end;
  qsorta(1,n);
  qsortb(1,n);
  qsortc(1,n);
  for i:=1 to n do
  begin
    s:=s+abs(d[i]-i);
    k:=k+s div 99999997;
    s:=s mod 99999997;
  end;
  write((s+k mod 2*99999997) div 2);
  close(input);close(output);
end.











