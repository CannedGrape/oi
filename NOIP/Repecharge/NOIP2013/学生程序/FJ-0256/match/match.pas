var
  n,i,j,k,s:longint;
  a,b:array [1..100000] of longint;
  c,d:record
    s,p:array [1..100000] of longint;
  end;
procedure kp1(x,y:longint);
var
  i,j,mid,r:longint;
begin
  i:=x;
  j:=y;
  mid:=c.s[(x+y)div 2];
  repeat
    while c.s[i]<mid do inc(i);
    while c.s[j]>mid do dec(j);
    if i<=j then
    begin
      r:=c.s[i];
      c.s[i]:=c.s[j];
      c.s[j]:=r;
      r:=c.p[i];
      c.p[i]:=c.p[j];
      c.p[j]:=r;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<y then kp1(i,y);
  if j>x then kp1(x,j);
end;
procedure kp2(x,y:longint);
var
  i,j,mid,r:longint;
begin
  i:=x;
  j:=y;
  mid:=d.s[(x+y)div 2];
  repeat
    while d.s[i]<mid do inc(i);
    while d.s[j]>mid do dec(j);
    if i<=j then
    begin
      r:=d.s[i];
      d.s[i]:=d.s[j];
      d.s[j]:=r;
      r:=d.p[i];
      d.p[i]:=d.p[j];
      d.p[j]:=r;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<y then kp2(i,y);
  if j>x then kp2(x,j);
end;
procedure kp3(x,y:longint);
var
  i,j,mid,r:longint;
begin
  i:=x;
  j:=y;
  mid:=c.p[(x+y)div 2];
  repeat
    while c.p[i]<mid do inc(i);
    while c.p[j]>mid do dec(j);
    if i<=j then
    begin
      r:=c.p[i];
      c.p[i]:=c.p[j];
      c.p[j]:=r;
      r:=d.p[i];
      d.p[i]:=d.p[j];
      d.p[j]:=r;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<y then kp2(i,y);
  if j>x then kp2(x,j);
end;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  close(input);
  c.s:=a;
  d.s:=b;
  for i:=1 to n do begin c.p[i]:=i; d.p[i]:=i end;
  kp1(1,n);
  kp2(1,n);
  kp3(1,n);
  for i:=1 to n do
  begin
    k:=c.p[i]-d.p[i];
    if k>0 then
    begin
      for j:=i+1 to n do
      if (c.p[j]>=d.p[i])and(c.p[j]<=c.p[i]) then
      inc(c.p[j]);
    end else
    if k<0 then
    begin
      for j:=i+1 to n do
      if (c.p[j]<=d.p[i])and(c.p[j]>=c.p[i]) then
      dec(c.p[j]);
    end;
    if k<>0 then
    k:=2*abs(k)-1;
    s:=(s+((k*k)mod 99999997)) mod 99999997;
  end;
  write(s);
  close(output);
end.
