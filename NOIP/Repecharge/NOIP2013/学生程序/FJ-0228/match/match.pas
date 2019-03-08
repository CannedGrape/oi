const dis=99999997;
type gc=array [0..100000] of longint;
var
  i,j,m,n,k,l,r:longint;
  a,b,t,ts:gc;
procedure cha(l,r:longint;var f,a:gc);
var
  i,j,k:longint;
begin
  k:=(l+r) div 2;
  if l<k then cha(l,k,f,a);
  if k+1<r then cha(k+1,r,f,a);
  for i:=l to r do ts[i]:=f[i];
  i:=l;j:=k+1;
  repeat
    if a[ts[i]]>a[ts[j]] then
    begin
      f[i+j-k-1]:=ts[j];
      inc(j);
    end
    else
    begin
      f[i+j-k-1]:=ts[i];
      inc(i);
    end;
  until (i>k) or (j>r);
  while not (i>k) do
  begin
    f[i+j-k-1]:=ts[i];
    inc(i);
  end;
  while not (j>r) do
  begin
    f[i+j-k-1]:=ts[j];
    inc(j);
  end;
end;
procedure qS(l,r:longint;var f,a:gc);
var
  i,j,x:longint;
begin
  i:=l;j:=r;x:=a[f[(l+r) div 2]];
  repeat
    while a[f[i]]<x do inc(i);
    while a[f[j]]>x do dec(j);
    if not (i>j) then
    begin
      f[0]:=f[i];f[i]:=f[j];f[j]:=f[0];
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qS(l,j,f,a);
  if i<r then qS(i,r,f,a);
end;
function dis_pat(l,r:longint):int64;
var
  i,j,k:longint;
begin
  k:=(l+r) div 2;dis_pat:=0;
  if l<k then dis_pat:=(dis_pat+dis_pat(l,k)) mod dis;
  if k+1<r then dis_pat:=(dis_pat+dis_pat(k+1,r)) mod dis;
  for i:=l to r do t[i]:=a[i];
  i:=l;j:=k+1;
  repeat
    if t[i]<t[j] then
    begin
      a[l+i-l+j-k-1]:=t[i];
      inc(i);
    end
    else
    begin
      a[i+j-k-1]:=t[j];
      inc(j);
      dis_pat:=(dis_pat+k+1-i) mod dis;
    end;
  until (i>k) or (j>r);
  while not (i>k) do
  begin
    a[i+j-k-1]:=t[i];
    inc(i);
  end;
  while not (j>r) do
  begin
    a[i+j-k-1]:=t[j];
    inc(j);
  end;
end;
begin
  assign(input,'match.in');reset(input);assign(output,'match.out');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do t[i]:=i;
  cha(1,n,t,a);
  for i:=1 to n do a[t[i]]:=i;
  for i:=1 to n do t[i]:=i;
  cha(1,n,t,b);
   for i:=1 to n do a[i]:=t[a[i]];
  writeln(dis_pat(1,n));
  close(input);close(output);
end.
