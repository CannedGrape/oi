var i,m,n,ans,x,y,tmp:longint;g:array[0..1000000] of longint;
procedure dfs(t:longint);
var i,j:longint;
begin
  x:=0;
  y:=t div 2;
  {for i:=1 to t do
  if g[2*i]=0 then
  inc(y);}
  for i:=1 to y do
  begin
  if ((g[2*i]>g[2*i+1])and(g[2*i]>g[2*i-1]))
  then inc(x);
  end;
  if x= y  then
  begin
  if t>ans then
  ans:=t;
  exit;
  end;
  x:=0;
  for i:=1 to y  do
  begin
  if ((g[2*i]<g[2*i+1])and(g[2*i]<g[2*i-1]))
  then inc(x);
  end;
  if x= y then
  begin
  if t>ans then
  ans:=t;
  exit;
  end;
  for i:=1 to t do
  begin
  tmp:=g[i];
  for j:=i to t do
  g[j]:=g[j+1];
  dfs(t-1);
  for j:=t downto i+1 do
  g[j]:=g[j-1];
  g[i]:=tmp;
  end;
end;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do
  read(g[i]);
  dfs(n);
  writeln(ans);
  close(input);close(output);
end.

