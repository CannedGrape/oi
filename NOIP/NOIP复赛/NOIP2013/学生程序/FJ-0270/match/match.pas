const modn=99999997;
type node=record
       val,pos,id:longint;
     end;
var a,b:array[0..100010]of node;
    n,i,ans:longint;
procedure swap(var a,b:node);
var t:node;
begin
  t:=a;a:=b;b:=t;
end;
procedure qsort1(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=a[(l+r) shr 1].val;
  repeat
    while a[i].val<m do inc(i);
    while a[j].val>m do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]);inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort1(i,r);
  if l<j then qsort1(l,j);
end;
procedure qsort2(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=b[(l+r) shr 1].val;
  repeat
    while b[i].val<m do inc(i);
    while b[j].val>m do dec(j);
    if i<=j then
    begin
      swap(b[i],b[j]);inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort2(i,r);
  if l<j then qsort2(l,j);
end;
procedure qsort3(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=a[(l+r) shr 1].pos;
  repeat
    while a[i].pos<m do inc(i);
    while a[j].pos>m do dec(j);
    if i<=j then
    begin
      swap(a[i],a[j]);inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort3(i,r);
  if l<j then qsort3(l,j);
end;
procedure merge(l,m,r:longint);
var i,j,k:longint;
begin
  i:=l;j:=m+1;k:=l-1;
  while (i<=m)and(j<=r) do
  begin
    inc(k);
    if a[i].id<a[j].id then
    begin
      b[k].id:=a[i].id;inc(i);
    end else
    if a[j].id<a[i].id then
    begin
      b[k].id:=a[j].id;inc(j);ans:=(ans+(m-i+1)) mod modn;
    end;
  end;
  while i<=m do
  begin
    inc(k);b[k].id:=a[i].id;inc(i);
  end;
  while j<=r do
  begin
    inc(k);b[k].id:=a[j].id;inc(j);
  end;
  for i:=l to r do a[i].id:=b[i].id;
end;
procedure mergesort(l,r:longint);
var m:longint;
begin
  if l=r then exit;
  m:=(l+r) shr 1;
  mergesort(l,m);
  mergesort(m+1,r);
  merge(l,m,r);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i].val);
  for i:=1 to n do read(b[i].val);
  for i:=1 to n do a[i].pos:=i;
  for i:=1 to n do b[i].id:=i;
  qsort1(1,n);
  qsort2(1,n);
  for i:=1 to n do a[i].id:=b[i].id;
  qsort3(1,n);
  ans:=0;
  mergesort(1,n);
  writeln(ans);
  close(input);close(output);
end.
