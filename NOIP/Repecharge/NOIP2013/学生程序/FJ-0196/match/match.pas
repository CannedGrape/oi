//match
var a,b,c,d,e,f,q:array[0..100001] of longint;
  i,j,n,m,ans:longint;
procedure qs(l,r:longint);
var i,j,x:longint;
begin
  i:=l;j:=r;x:=a[(l+r) shr 1];
  repeat
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
    begin
      a[0]:=a[i];a[i]:=a[j];a[j]:=a[0];
      b[0]:=b[i];b[i]:=b[j];b[j]:=b[0];
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then qs(i,r);
  if l<j then qs(l,j);
end;
procedure ms(l,r:longint);
var i,j,x,t:longint;
begin
  if l=r then exit;
  x:=l+(r-l) div 2;
  ms(l,x);
  ms(x+1,r);
  i:=l;j:=x+1;t:=l;
  while t<=r do
  begin
    if (i<=x) and not((f[i]>f[j]) and (j<=r)) then
    begin
      q[t]:=f[i];inc(i);
    end
    else
    begin
      q[t]:=f[j];inc(j);
      ans:=(ans+x-i+1);
      if ans > 99999997 then ans:=ans-99999997;
    end;
    inc(t);
  end;
  for i:=l to r do f[i]:=q[i];
end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do b[i]:=i;
  for i:=1 to n do read(a[i]);
  readln;
  qs(1,n);
  for i:=1 to n do c[b[i]]:=i;
  for i:=1 to n do b[i]:=i;
  for i:=1 to n do read(a[i]);
  readln;
  qs(1,n);
  for i:=1 to n do d[b[i]]:=i;
  for i:=1 to n do e[c[i]]:=i;
  for i:=1 to n do f[i]:=e[d[i]];
  ans:=0;
  ms(1,n);
  writeln(ans);
  close(input);close(output);
end.
