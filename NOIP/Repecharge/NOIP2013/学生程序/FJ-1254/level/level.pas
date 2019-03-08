var     a:array[1..1000,1..1000]of longint;
       b:array[1..1000]of longint;
         c:array[1..1000000]of longint;
            i,j,t,n,m,k,sum:longint;
procedure qsort(l,r:longint);
var i,j,x,t:longint;
begin
  i:=l;j:=r;x:=c[(i+j) div 2];
  repeat
    while c[i]<x do inc(i);
    while x<c[j] do dec(j);
    if i<=j then begin
     t:=c[i]; c[i]:=c[j];c[j]:=t;
     inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(Input,'level.in');assign(output,'level.out');
  reset(input);rewrite(output);
  read(n,m);   t:=0;
  for i:=1 to m do
    begin
      read(b[i]);
      t:=t+b[i];
      for j:=1 to b[i] do
          read(a[i,j]);
    end;
  for i:=1 to m do
    for j:=1 to b[i] do
      begin
        inc(k);
        c[k]:=a[i,j];
      end;
  qsort(1,t);
  sum:=1;
  for i:=2 to  t do
    if c[i-1]<>c[i] then inc(sum);
  if sum mod 2=1 then write(sum div 2+1)
    else write(sum div 2);
  close(input);close(output);
end.
