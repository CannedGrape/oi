var i,n,m,q,x,y:longint;a,b,c,d,e,ans:array[0..50000] of longint;f:array[0..50000] of boolean;
procedure dfs(k:longint);
var j:longint;
begin
  if k=e[i] then
  begin
  if x>ans[i] then
  ans[i]:=x;
  x:=0;
  exit;
  end;
  for j:=1 to m do
  begin
  if (a[j]= k)and(f[k])and(x>=ans[i]) then
  begin
  if x=0 then begin y:=x;x:=c[j];end;
  f[k]:=false;
  if c[j]<x then begin y:=x;x:=c[j];end;
  dfs(b[j]);
  f[k]:=true;
  x:=y;
  end;
  if (b[j]= k)and(f[k]) then
  begin
  if x=0 then begin y:=x;x:=c[j];end;
  f[k]:=false;
  if c[j]<x then begin y:=x;x:=c[j];end;
  dfs(a[j]);
  f[k]:=true;
  x:=y;
  end;
  end;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
  readln(a[i],b[i],c[i]);
  end;
  readln(q);
  for i:=1 to q do
  readln(d[i],e[i]);
  fillchar(f,sizeof(f),true);
  for i:=1 to q do
  begin
  dfs(d[i]);
  if ans[i]=0 then ans[i]:=-1;
  writeln(ans[i]);
  end;
  close(input);close(output);
end.
