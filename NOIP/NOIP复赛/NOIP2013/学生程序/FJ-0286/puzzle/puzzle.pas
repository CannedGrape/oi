const d:array[1..4,1..2] of -1..1
       =((-1,0),(1,0),(0,-1),(0,1));
var a:array[1..30,1..30] of 0..1;
    b:array[1..30,1..30,1..30,1..30] of 0..1;
    n,m,q,i,j,ex,ey,sx,sy,tx,ty,ans:longint;
procedure dfs(e1,e2,s1,s2,s:longint);
var i,x,y:longint;
begin
  if s+abs(s1-tx)+abs(s2-ty)>=ans then exit;
  if(s1=tx)and(s2=ty)then
  begin
    if s<ans then ans:=s;
    exit;
  end;
  for i:=1 to 4 do
  begin
    x:=e1+d[i,1];y:=e2+d[i,2];
    if(x>=1)and(x<=n)and(y>=1)and(y<=m)then
    if(a[x,y]=1)and(b[e1,e2,x,y]=0)then
    begin
      b[e1,e2,x,y]:=1;
      if(x=s1)and(y=s2)then dfs(x,y,e1,e2,s+1)
      else dfs(x,y,s1,s2,s+1);
      b[e1,e2,x,y]:=0;
    end;
  end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do read(a[i,j]);
    readln;
  end;
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    ans:=maxlongint;dfs(ex,ey,sx,sy,0);
    if ans=maxlongint then writeln(-1)
    else writeln(ans);
  end;
  close(input);close(output);
end.











