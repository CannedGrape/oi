program e3;
var n,p,i,j,k,q:longint;
    a,b,c:array[1..1000000] of longint;
begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  read(n,p);
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];c[1]:=a[1];
  for i:=2 to n do
  for j:=1 to i do
  begin
    if a[j]>=0 then b[i]:=b[i]+a[j];
    if(a[j]<0)and(j<>i) then b[i]:=0;
    if(a[j]<0)and(j=i)then b[i]:=b[i]+a[j];
  end;
  for i:=2 to n do c[i]:=-1001;
  q:=-1001;
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
    begin
      k:=c[j]+b[j];
      if k>c[i] then c[i]:=k;
    end;
    if c[i]>q then q:=c[i];
  end;
  write(q);
  close(input);close(output);
end.
