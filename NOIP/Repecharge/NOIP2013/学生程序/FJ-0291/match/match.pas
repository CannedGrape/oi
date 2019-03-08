const pp:int64=99999997;
var h1,h2,notneed,s1,s2,num1,num2:array[0..110000] of int64;
ans:int64;
i,j,k,n:longint;

procedure qsort1(l,r:longint);
var x,y:longint;
t,mid:int64;
begin
  x:=l; y:=r;
  mid:=h1[(l+r) shr 1];
  repeat
  while h1[x]<mid do inc(x);
  while h1[y]>mid do dec(y);
  if x<=y then
  begin
    t:=h1[x]; h1[x]:=h1[y]; h1[y]:=t;
    t:=s1[x]; s1[x]:=s1[y]; s1[y]:=t;
    inc(x); dec(y);
  end;
  until x>y;
  if x<r then qsort1(x,r);
  if y>l then qsort1(l,y);
end;

procedure qsort2(l,r:longint);
var x,y:longint;
t,mid:int64;
begin
  x:=l; y:=r;
  mid:=h2[(l+r) shr 1];
  repeat
  while (h2[x]<mid)   do inc(x);
  while (h2[y]>mid)   do dec(y);
  if x<=y then
  begin
    t:=h2[x]; h2[x]:=h2[y]; h2[y]:=t;
    t:=s2[x]; s2[x]:=s2[y]; s2[y]:=t;
    inc(x); dec(y);
  end;
  until x>y;
  if x<r then qsort2(x,r);
  if y>l then qsort2(l,y);
end;

begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(h1[i]);
    s1[i]:=i;
  end;
  for i:=1 to n do
  begin
    read(h2[i]);
    s2[i]:=i;
  end;
  qsort1(1,n);
  qsort2(1,n);
  ans:=0;
  for i:=1 to n do
  begin
    num1[s1[i]]:=i;
    num2[s2[i]]:=i;
  end;
  for i:=n-1 downto 1 do
  begin
    if num1[i+1]=num2[i+1] then notneed[i]:=notneed[i+1]+1
    else notneed[i]:=notneed[i+1];
    if s2[num1[i]]>i then
    ans:=(ans+(notneed[i]-notneed[s2[num1[i]]])+s2[num1[i]]-i) mod pp;
  end;
  writeln(ans mod pp);
  close(input); close(output);
end.






