type ar=array[1..100000]of longint;
var i,j,n,p:longint; a,b,c,d:ar;
procedure kp(l,r:longint;var a:ar);
var i,j,m,t:longint;
begin
  i:=l;j:=r;m:=a[(l+r)div 2];
  repeat
    while a[i]<m do inc(i);
    while a[j]>m do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;inc(i);dec(j);
    end;
  until i>j;
  if l<j then kp(l,j,a);
  if i<r then kp(i,r,a);
end;
procedure kpp(var a:ar);
var i,j,t:longint;
begin
  for i:=1 to n do
    for j:=1 to n-1 do
    if a[i]<a[i+1] then begin t:=a[i];a[i]:=a[i+1];a[i+1]:=t;end;end;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
  kp(1,i,a); j:=1;
  if a[1]>0 then
  begin
  inc(b[i],a[j]);
  while (a[j]>0) and (j<i)do begin inc(j);b[i]:=b[i]+a[j];end;
  end
  else b[i]:=a[1];
  end;
  for i:=1 to n do
  if (i=1) then c[i]:=b[i]
  else
  begin c[i]:=b[1]+c[1];
  for j:=1 to i-1 do
  if  b[j]+c[j]>c[i] then c[i]:=(b[j]+c[j]);
  end;
  kp(1,n,c);
  if c[i]<0 then write('-');
  writeln(abs(c[i])mod p);
  close(input);close(output);
end.

