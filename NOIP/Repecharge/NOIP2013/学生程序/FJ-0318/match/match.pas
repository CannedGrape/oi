const fuck=99999997;
var n,i,j,ans,t:longint;
    a,b,c:array[0..100000]of longint;

{procedure work(l,m,r:longint);
var left,count,mid:longint;
begin
  left:=l; mid:=m+1; count:=l;

  if ((left>=m)or(mid>r))and (count<=r) then
  begin
    b[left]:=b[mid]; inc(count); inc(left);
  end else begin
    ans:=(ans+m-left+1)mod fuck;
    b[mid]:=b[r];
    inc(count);
  end;
end;

procedure pp(l,r:longint);
var m:longint;
begin
  m:=(l+r)div 2;
  while l<m do pp(l,m);
  while r>m do pp(m,r);
  work(l,m,r);
end;}

procedure sort(l,r: longint);
var i,j,x,y: longint;
begin
  i:=l; j:=r; x:=a[(l+r) div 2];
  repeat
    while a[i]<x do inc(i);
    while x<a[j] do dec(j);
    if not(i>j) then
    begin
      y:=a[i]; a[i]:=a[j]; a[j]:=y;
      y:=b[i]; b[i]:=b[j]; b[j]:=y;
      inc(i); dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);  ans:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  sort(1,n);
  for i:=1 to n do c[i]:=b[i];
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  sort(1,n);
  for i:=1 to n do
  for j:=1 to n do
  if b[i]=c[j] then
  begin
    b[i]:=j;
    break;
  end;
  //pp(1,n);
  for i:=1 to n-1 do
  for j:=i+1 to n do
  begin
    if b[i]>b[j] then
    begin
      inc(ans);
      ans:=ans mod fuck;
      t:=b[i];
      b[i]:=b[j];
      b[j]:=t;
    end;
  end;
  writeln(ans);
  close(input); close(output);
end.



