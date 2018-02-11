var n,i,j,k,ans,tot,num,top,t:longint;
    a,b,c,d,f,wh1,wh2,wh,g:array[1..100000] of longint;
procedure qsort(l,r:longint);
var i,j,mid,t:longint;
begin
  i:=l; j:=r; mid:=a[(l+r) div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      t:=a[i]; a[i]:=a[j]; a[j]:=t;
      t:=wh[i]; wh[i]:=wh[j]; wh[j]:=t;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;
begin
  assign(input,'match.in'); reset(input);
  assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  d:=a;
  for i:=1 to n do wh[i]:=i;
  qsort(1,n);
  b:=a;
  wh1:=wh;
  for i:=1 to n do read(a[i]);
  c:=a;
  for i:=1 to n do wh[i]:=i;
  qsort(1,n);
  wh2:=wh;
  for i:=1 to n do
  begin
    f[wh1[i]]:=wh2[i];
    g[wh2[i]]:=wh1[i];
    if wh1[i]<>wh2[i] then inc(tot);
  end;
  top:=1;
  while top<n do
  begin
    while f[top]=top do inc(top);
    if top<n then
      for i:=f[top]-1 downto top do
      begin
        t:=g[i]; g[i]:=g[i+1]; g[i+1]:=t;
        t:=f[g[i]]; f[g[i]]:=f[g[i+1]]; f[g[i+1]]:=t;
        inc(ans);
        ans:=ans mod 99999997;
      end;
  end;
  writeln(ans);
  close(input); close(output);
end.
