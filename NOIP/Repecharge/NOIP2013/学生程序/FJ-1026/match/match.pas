var
  a:array[1..10000] of longint;
  b:array[1..2,1..10000] of longint;
  i,j,n,total:longint;
procedure qsort(l,r:longint);
var
  i,j,p,mid:longint;
begin
  i:=l;j:=r;
  mid:=a[(l+r) div 2];
  repeat
  while a[i]<mid do inc(i);
  while a[j]>mid do dec(j);
  if i<=j then
  begin
  p:=a[i]; a[i]:=a[j]; a[i]:=p;
  inc(i);dec(j);
  end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(b[1,i],b[2,i]);
  qsort(b[1,i],b[2,i]);
  inc(total);
  writeln(total mod 99999997);
  close(input);close(output);
end.
