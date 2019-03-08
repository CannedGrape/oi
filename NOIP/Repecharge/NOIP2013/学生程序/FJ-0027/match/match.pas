var a,b,c,d,e,f:array[0..100010]of int64;
    mo,ans:int64;
    n,i,j,k:longint;
procedure sorta(l,r:longint);
var i,j:longint;
    x:int64;
begin
  i:=l;j:=r;
  x:=a[(l+r)shr 1];
  repeat
    while(a[i]<x)do inc(i);
    while(x<a[j])do dec(j);
    if i<=j then
    begin
      a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
      c[0]:=c[i];c[i]:=c[j];c[j]:=c[0];
      inc(i);j:=j-1;
    end;
  until i>j;
  if l<j then sorta(l,j);
  if i<r then sorta(i,r);
end;
procedure sortc(l,r:longint);
var i,j:longint;
    x:int64;
begin
  i:=l;j:=r;
  x:=c[(l+r)shr 1];
  repeat
    while c[i]<x do inc(i);
    while x<c[j] do dec(j);
    if i<=j then
    begin
      a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
      c[0]:=c[i];c[i]:=c[j];c[j]:=c[0];
      e[0]:=e[i];e[i]:=e[j];e[j]:=e[0];
      inc(i);j:=j-1;
    end;
  until i>j;
  if l<j then sortc(l,j);
  if i<r then sortc(i,r);
end;
begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);rewrite(output);
  readln(n);mo:=99999997;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do c[i]:=i;sorta(1,n);
  for i:=1 to n do e[i]:=i;sortc(1,n);
  for i:=1 to n do begin d[i]:=e[i];a[i]:=b[i];end;sorta(1,n);
  for i:=1 to n do e[i]:=i;sortc(1,n);
  for i:=1 to n do begin a[i]:=d[i];b[i]:=e[i];end;
  ans:=0;
  for i:=1 to n do
  begin
    c[a[i]]:=i;
    d[b[i]]:=i;
  end;
  for i:=1 to n do e[i]:=c[i]-d[i];
  for i:=1 to n do f[i]:=e[b[i]];
  i:=n;
  ans:=0;
  for i:=n downto 1 do
  begin
    j:=d[a[i]];
    ans:=(ans+abs(f[b[i]]))mod mo;
    for k:=j to i-1 do
    begin
      f[k]:=f[k+1]+1;
//      b[k]:=b[k+1];
    end;
    f[i]:=0;
  end;
  writeln(ans);
close(input);close(output);
end.
