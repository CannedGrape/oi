var
  n,i,j,k,z:longint;
  a,b,c:array[1..1000]of longint;
procedure qsort(l,r:integer);
var
  i,j,mid,p,w:integer;
begin
  i:=l;j:=r;
  mid:=a[(l+r)div 2];
  repeat
  while a[i]<mid do inc(i);
  while a[j]>mid do dec(j);
  if i<=j then
  begin
    p:=a[i];a[i]:=a[j];a[j]:=p;
    w:=b[i];b[i]:=b[j];b[j]:=w;
    inc(i);dec(j);
    k:=k+2;
  end;
  until i>j;
  if l<j then qsort(l,j);
  if r<i then qsort(r,i);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  for j:=1 to n do read(b[j]);
  k:=0;
  qsort(1,n);
  z:=k div 2;
  writeln(z mod 99999997);
  close(input);close(output);
end.
