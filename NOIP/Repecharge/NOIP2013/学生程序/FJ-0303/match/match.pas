program match;
type
  node=record
  a,b:longint;
  end;
var
  dp:array[0..2000,0..2000]of longint;
  a,b:array[0..2000]of node;
  c,d:array[0..2000]of longint;
  i,n,j:longint;
function max(a1,b1:longint):longint;
begin
  if a1>b1 then exit(a1)
  else exit(b1);
end;
procedure swap(var a1,b1:node);
var
 t:node;
begin
  t:=a1;a1:=b1;b1:=t;
end;
procedure qsorta(l,r:longint);
var
  l1,r1,key1,key2:longint;
begin
  l1:=l;r1:=r;
  key1:=a[(l1+r1)shr 1].a;
  key2:=a[(l1+r1)shr 1].b;
  repeat
    while (a[l1].a<key1)or((a[l1].a=key1)and(a[l1].b<key2))do inc(l1);
    while (a[r1].a>key1)or((a[r1].a=key1)and(a[r1].b>key2))do dec(r1);
    if l1<=r1 then
    begin
      swap(a[l1],a[r1]);
      inc(l1);dec(r1);
    end;
  until(l1>r1);
  if l1<r then qsorta(l1,r);
  if r1>l then qsorta(l,r1);
end;
procedure qsortb(l,r:longint);
var
  l1,r1,key1,key2:longint;
begin
  l1:=l;r1:=r;key1:=b[(l1+r1)shr 1].a;
  key2:=b[(l1+r1)shr 1].b;
  repeat
    while (b[l1].a<key1)or((b[l1].a=key1)and(b[l1].b<key2))do inc(l1);
    while (b[r1].a>key1)or((b[r1].a=key1)and(b[r1].b>key2))do dec(r1);
    if l1<=r1 then
    begin
      swap(b[l1],b[r1]);
      inc(l1);dec(r1);
    end;
  until(l1>r1);
  if l1<r then qsortb(l1,r);
  if r1>l then qsortb(l,r1);
end;
begin
  assign(input,'match.in');
  reset(input);
  read(n);
  for i:=1 to n do
  begin
   read(a[i].a);a[i].b:=i;
   c[i]:=a[i].a;
  end;
  for i:=1 to n do
  begin
   read(b[i].a);b[i].b:=i;
   d[i]:=b[i].a;
  end;
  qsorta(1,n);
  qsortb(1,n);
  for i:=1 to n do
  begin
    c[a[i].b]:=b[i].a;
  end;
  for i:=1 to n do
  begin
    for j:=1 to i do
    begin
      if c[i]=d[j] then
      dp[i,j]:=max((dp[i-1,j-1]+1)mod 99999997,dp[i,j])
      else
      dp[i,j]:=max(max(dp[i-1,j],dp[i,j-1]),dp[i,j])
    end;
  end;
  assign(output,'match.out');
  rewrite(output);
  writeln(n-dp[n,n]);
  close(input);close(output);
end.
