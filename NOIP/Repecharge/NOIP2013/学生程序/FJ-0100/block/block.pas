var
  n,m,i,j,k,l,p,r,ans,t,ans2:longint;
  a:array[0..100000]of longint;
procedure qs(l,r:longint);
var i,j,min,p:longint;
begin
  i:=l;j:=r;
  min:=maxlongint;
  for i:=l to r do
  if (a[i]<min)then begin t:=i;min:=a[i];end;
  ans:=ans+min;
  for i:=l to r do
  if a[i]<>0 then
    a[i]:=a[i]-min;
  min:=maxlongint;
  if l<t then  qs(l,t);
  if t<r then  qs(t,r);
  if (t=r)or(t=l)then inc(ans);
end;
begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  readln(n);a[0]:=0;m:=maxlongint;
  for i:=1 to n do
   read(a[i]);
  for i:=1 to n do
    if a[i]>t then t:=a[i];
  for i:=1 to n do
    if a[i]<m then m:=a[i];
  writeln(t+m);
  close(input);close(output);
end.
