program number;
var n,p,i:longint;a,b:array[1..1000001]of longint;
procedure qsort(l,r:longint);
var  i,j,x,t:longint;
begin
  i:=l;j:=r; x:=a[(i+j)div 2];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(n,p);
  for i:=1 to n do  read(a[i]);
  qsort(1,n);
  if (a[1]<0)and(a[n]<0) then begin
     write(a[n]);
     close(input);
     close(output);
     halt;
  end;
  for i:=2 to n do
    if a[i-1]>=0 then a[i]:=(a[i-1]+a[i]) mod p
      else a[i]:=a[1]mod p;
  b[1]:=a[1];
  for i:=2 to n do
    b[i]:=(b[i-1]+a[i-1])mod p;
  write(b[n]);
  close(input);close(output);
end.

