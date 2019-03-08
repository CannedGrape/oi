var n,i,x,k,tmp:longint;{f,c:array[0..100000,0..100000] of longint;}a,b:array[0..100000] of longint;f:boolean;ans,j,q:int64;
{procedure dfs(k:longint);
var i,tmp:longint;
begin
  if k>n-1 then
  begin
  if ans=0 then ans:=x;
  if x<ans then ans:=x;
  x:=0;
  exit;
  end;
  if (a[k]-b[k])*(a[k]-b[k])+(a[k+1]-b[[k+1])*(a[k+1]-b[k+1]) then
  begin
  tmp:=a[k];
  a[k]:=a[k+1];
  a[k+1]:=tmp;
  inc(x);
  end;
  dfs(k+1);}
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(a[i]);
  readln;
  for i:=1 to n do
  read(b[i]);
  {for i:=1 to n do
    for j:=1 to n do
  begin
  if f[i,j-1]+(a[i]-b[j])*(a[i]-b[j])<f[i,j] then
    begin
    f[i,j]:=f[i,j-1]+(a[i]-b[j])*(a[i]-b[j]);
    inc(c[i,j]);
    end;
  end;}
  f:=true;
  j:=0;
  while f do
  begin
  x:=0;
  for k:=1 to n-1 do
  if ((a[k]-b[k])*(a[k]-b[k])+(a[k+1]-b[k+1])*(a[k+1]-b[k+1]))>((a[k]-b[k+1])*(a[k]-b[k+1])+(a[k+1]-b[k])*(a[k+1]-b[k]))then
  begin
  tmp:=a[k];
  a[k]:=a[k+1];
  a[k+1]:=tmp;
  inc(x);
  end;
  if n <=1000 then
  begin
  for k:=1 to n do
  j:=j+(a[k]-b[k])*(a[k]-b[k]);
  if q=0 then begin q:=j;ans:=ans+x;end;
  if j<q then
  begin
  q:=j;
  ans:=ans+x;
  end;
  end;
  if n>1000  then
  ans:=ans+x;
  if x=0 then f:=false;
  end;
  writeln(ans mod 99999997);
  close(input);close(output);
end.
