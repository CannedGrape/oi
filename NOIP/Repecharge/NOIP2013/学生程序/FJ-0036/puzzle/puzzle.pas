var q,t,w,xx,yy,xxx,yyy,x,y,sx,sy,ex,ey,tx,ty,ans,n,m,i,j,k,l,o,p:longint;
   a,dis:array[0..40,0..40]of longint;
   z:array[0..1000000,1..3]of longint;
   last:array[0..40,0..40,1..4]of longint;
   pre:array[0..40,0..40,1..4,1..4]of longint;
   f:array[1..4,1..2]of longint=((1,0),(0,1),(0,-1),(-1,0));
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  for j:=1 to m do
  read(a[i,j]);
  for i:=1 to n do
  for j:=1 to m do
  for k:=1 to 4 do
  for l:=1 to 4 do
  pre[i,j,k,l]:=maxlongint;

  for i:=1 to n do
  for j:=1 to m do
  if a[i,j]=1 then
  begin
  a[i,j]:=0;
  for k:=1 to 4 do
  begin
  x:=i+f[k,1];y:=j+f[k,2];if a[x,y]=0 then continue;
  for l:=k to 4 do
  begin
  xx:=i+f[l,1];yy:=j+f[l,2];if a[xx,yy]=0 then continue;
  t:=0;w:=1;z[w,1]:=x;z[w,2]:=y;
  for o:=1 to n do
  for p:=1 to m do
  dis[o,p]:=maxlongint;
  dis[x,y]:=0;
  repeat
  inc(t);
  for o:=1 to 4 do
  begin
  xxx:=z[t,1]+f[o,1];yyy:=z[t,2]+f[o,2];
  if (a[xxx,yyy]=1)and(dis[xxx,yyy]>dis[z[t,1],z[t,2]]+1) then
    begin
    dis[xxx,yyy]:=dis[z[t,1],z[t,2]]+1;
    inc(w);z[w,1]:=xxx;z[w,2]:=yyy;
    end;
  end;
  until t=w;

  pre[i,j,k,l]:=dis[xx,yy];
  pre[i,j,l,k]:=dis[xx,yy];

  end;
  end;
  a[i,j]:=1;
  end;


  for o:=1 to q do
  begin
  read(ex,ey,sx,sy,tx,ty);
  if (sx=tx)and(sy=ty) then
  begin
  writeln(0);continue;
  end;
  a[sx,sy]:=0;
  t:=0;w:=1;z[w,1]:=ex;z[w,2]:=ey;
  for i:=1 to n do
  for j:=1 to m do
  dis[i,j]:=maxlongint;
  dis[ex,ey]:=0;
  repeat
  inc(t);
  for i:=1 to 4 do
  begin
  x:=z[t,1]+f[i,1];
  y:=z[t,2]+f[i,2];
  if (a[x,y]=1)and(dis[z[t,1],z[t,2]]+1<dis[x,y]) then
  begin
  inc(w);dis[x,y]:=dis[z[t,1],z[t,2]]+1;z[w,1]:=x;z[w,2]:=y;
  end;
  end;
  until t=w;
  a[sx,sy]:=1;

  t:=0;w:=0;
  for i:=1 to n do
  for j:=1 to m do
  for k:=1 to 4 do
  last[i,j,k]:=maxlongint;
  for i:=1 to 4 do
  if (dis[sx+f[i,1],sy+f[i,2]]<>maxlongint)and(a[sx+f[i,1],sy+f[i,2]]<>0)then
  begin
  inc(w);z[w,1]:=sx;z[w,2]:=sy;z[w,3]:=i;
  last[sx,sy,i]:=dis[sx+f[i,1],sy+f[i,2]];
  end;

  repeat
  inc(t);
  for i:=1 to 4 do
  begin
  x:=z[t,1]+f[i,1];y:=z[t,2]+f[i,2];
  if (a[x,y]=1)and(pre[z[t,1],z[t,2],z[t,3],i]<>maxlongint) then
  if last[z[t,1],z[t,2],z[t,3]]+pre[z[t,1],z[t,2],z[t,3],i]+1<last[x,y,5-i] then
  begin
  last[x,y,5-i]:=last[z[t,1],z[t,2],z[t,3]]+pre[z[t,1],z[t,2],z[t,3],i]+1;
  inc(w);z[w,1]:=x;z[w,2]:=y;z[w,3]:=5-i;
  end;
  end;
  until t=w;

  ans:=maxlongint;
  for i:=1 to 4 do
  if last[tx,ty,i]<ans then ans:=last[tx,ty,i];
  if ans=maxlongint then writeln(-1) else writeln(ans);
  end;
  close(input);
  close(output); 
end.
