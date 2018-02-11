var n,m,i,q,j,ans:longint;a:array[0..30,0..30] of integer;ex,ey,sx,sy,tx,ty:array[0..1000] of integer;
procedure dfs(x,y,t:integer);
begin
  if (x=tx[i])and(y=ty[i]) then
  begin
  if ans=0 then ans:=t;
  if t<ans then ans:=t;
  exit;
  end;
  if a[sx[i], sy[i]+1]=1 then
  begin sy[i]:=sy[i]+1;
     dfs(ex[i],ey[i],t+1);
     sy[i]:=sy[i]-1;
  end;
  if a[sx[i]+1, sy[i]]=1 then
  begin sx[i]:=sx[i]+1;
     dfs(ex[i],ey[i],t+1);
     sx[i]:=sx[i]-1;
  end;
  if a[sx[i]-1, sy[i]]=1 then
  begin sx[i]:=sx[i]-1;
     dfs(ex[i],ey[i],t+1);
     sx[i]:=sx[i]+1;
  end;
  if a[sx[i], sy[i]-1]=1 then
  begin sy[i]:=sy[i]-1;
     dfs(ex[i],ey[i],t+1);
     sy[i]:=sy[i]+1;
  end;
  if (x=sx[i])and(y+1=sy[i]) then
  begin y:=y+1;
     dfs(x,y+1,t+1);
     y:=y-1;
  end;
  if (x+1=sx[i])and(y=sy[i]) then
  begin x:=x+1;
     dfs(x+1,y,t+1);
     x:=x-1;
  end;
  if (x-1=sx[i])and(y=sy[i]) then
  begin x:=x-1;
     dfs(x-1,y,t+1);
     x:=x+1;
  end;
  if (x=sx[i])and(y-1=sy[i]) then
  begin y:=y-1;
     dfs(x,y-1,t+1);
     y:=y+1;
  end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for j:=1 to n do
  begin
    for i:=1 to m do
    read(a[i,j]);
    readln;
  end;
  for i:=1 to q do
  readln(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);
  for i:=1 to q do
  begin
  ans:=0;
  dfs(ex[i],ey[i],0);
  if ans=0 then ans:=-1;
  writeln(ans);
  end;
  close(input);close(output);
end.

