var z,x,a,b,f:array[0..200000] of longint;
    i,n,s,d,ans,zongans:longint;
procedure kp1(l,r:longint);
var i,j,mid,p:longint;
begin
  i:=l;j:=r;mid:=a[(l+r)>>1];
  repeat
  while a[i]<mid do inc(i);
  while a[j]>mid do dec(j);
  if i<=j then
  begin
    p:=a[i];a[i]:=a[j];a[j]:=p;
    p:=b[i];b[i]:=b[j];b[j]:=p;
    inc(i);
    dec(j);
  end;
  until i>j;
  if i<r then kp1(i,r);
  if l<j then kp1(l,j);
end;
procedure kp2(l,r:longint);
var i,j,mid,p:longint;
begin
  i:=l;j:=r;mid:=b[(l+r)>>1];
  repeat
  while b[i]<mid do inc(i);
  while b[j]>mid do dec(j);
  if i<=j then
  begin
    p:=x[i];x[i]:=x[j];x[j]:=p;
    p:=b[i];b[i]:=b[j];b[j]:=p;
    inc(i);
    dec(j);
  end;
  until i>j;
  if i<r then kp2(i,r);
  if l<j then kp2(l,j);
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=i;
  end;
  kp1(1,n);
  for i:=1 to n do
  begin
    z[b[i]]:=i;
    read(b[i]);
    x[i]:=i;
  end;
  kp2(1,n);
  for i:=n downto 1 do
  begin
    s:=i-x[z[i]];
    d:=x[z[i]]-1;
    ans:=0;
    while d>0  do
    begin
      ans:=ans+f[d];
      d:=d-d and (-d);
    end;
    zongans:=(s+ans+zongans) mod 99999997;
    d:=x[z[i]];
    while d<=n do
    begin
      f[d]:=f[d]+1;
      d:=d+d and (-d);
    end;
  end;
  writeln(zongans);
  close(input);
  close(output);
end.

