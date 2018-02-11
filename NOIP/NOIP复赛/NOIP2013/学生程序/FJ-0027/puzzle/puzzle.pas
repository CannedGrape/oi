type point=record x,y:integer;end;
var qq,n,m,i,j,ii,l,r,k:longint;
    a,vis,cal:array[0..35,0..35]of integer;
    fa:array[0..1000]of integer;
    q:array[0..1000000]of point;
    ans:array[0..1000000]of longint;
    dis:array[0..1000,0..1000]of longint;
    e,s,t,now,s1,s2:point;
    b:boolean;
procedure work(i,j,x:integer);
begin
  fa[30*(i-1)+j]:=x;vis[i,j]:=1;
  if(i-1>0)and(a[i-1,j]=1)and(vis[i-1,j]=0)then work(i-1,j,x);
  if(i+1<=n)and(a[i+1,j]=1)and(vis[i+1,j]=0)then work(i+1,j,x);
  if(j-1>0)and(a[i,j-1]=1)and(vis[i,j-1]=0)then work(i,j-1,x);
  if(j+1<=m)and(a[i,j+1]=1)and(vis[i,j+1]=0)then work(i,j+1,x);
end;
function calc(i,j:integer):integer;
begin
  calc:=1;
  if(a[i-1,j]=1)and(a[i,j-1]=1)and(a[i-1,j-1]=1)then exit;
  if(a[i-1,j]=1)and(a[i,j+1]=1)and(a[i-1,j+1]=1)then exit;
  if(a[i+1,j]=1)and(a[i,j+1]=1)and(a[i+1,j+1]=1)then exit;
  if(a[i+1,j]=1)and(a[i,j-1]=1)and(a[i+1,j-1]=1)then exit;
  calc:=0;
end;
procedure add(i,j,xx:longint);
begin
  vis[i,j]:=1;
  r:=r+1;
  q[r].x:=i;
  q[r].y:=j;
  ans[r]:=xx;
end;
function dfs:longint;
begin
  l:=1;r:=1;q[1].x:=e.x;
  q[1].y:=e.y;vis[e.x,e.y]:=1;//remember to -2
  while l<=r do
  begin
    now:=q[l];
    if(a[now.x+1,now.y]=1)and(vis[now.x+1,now.y]=0)then
    begin
      r:=r+1;
      q[r].x:=now.x+1;
      q[r].y:=now.y;
      vis[now.x+1,now.y]:=vis[now.x,now.y]+1;
      if(q[r].x=s.x)and(q[r].y=s.y)then
      exit(vis[now.x,now.y]-1);
    end;
    if(a[now.x-1,now.y]=1)and(vis[now.x-1,now.y]=0)then
    begin
      r:=r+1;
      q[r].x:=now.x-1;
      q[r].y:=now.y;
      vis[now.x-1,now.y]:=vis[now.x,now.y]+1;
      if(q[r].x=s.x)and(q[r].y=s.y)then
      exit(vis[now.x,now.y]-1);
    end;
    if(a[now.x,now.y+1]=1)and(vis[now.x,now.y+1]=0)then
    begin
      r:=r+1;
      q[r].x:=now.x;
      q[r].y:=now.y+1;
      vis[now.x,now.y+1]:=vis[now.x,now.y]+1;
      if(q[r].x=s.x)and(q[r].y=s.y)then
      exit(vis[now.x,now.y]-1);
    end;
    if(a[now.x,now.y-1]=1)and(vis[now.x,now.y-1]=0)then
    begin
      r:=r+1;
      q[r].x:=now.x;
      q[r].y:=now.y-1;
      vis[now.x,now.y-1]:=vis[now.x,now.y]+1;
      if(q[r].x=s.x)and(q[r].y=s.y)then
      exit(vis[now.x,now.y]-1);
    end;
    l:=l+1;
  end;
end;
begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);rewrite(output);
  readln(n,m,qq);
  for i:=1 to n do
  for j:=1 to m do read(a[i,j]);
  for i:=1 to 1000 do fa[i]:=i;
  for i:=1 to n do
  for j:=1 to m do
  if(a[i,j]=1)and(vis[i,j]=0)then work(i,j,30*(i-1)+j);
  for i:=1 to n do
  for j:=1 to m do
  cal[i,j]:=calc(i,j);
  for ii:=1 to qq do
  begin
    readln(e.x,e.y,s.x,s.y,t.x,t.y);
    if(fa[30*(s.x-1)+s.y]<>fa[30*(t.x-1)+t.y])
    or(fa[30*(s.x-1)+s.y]<>fa[30*(e.x-1)+e.y])
    or(fa[30*(e.x-1)+e.y]<>fa[30*(t.x-1)+t.y])
    or(a[s.x,s.y]=0)or(a[t.x,t.y]=0)or(a[e.x,e.y]=0)then
    begin
      writeln(-1);
      continue;
    end;
    l:=abs(s.x-t.x)+abs(s.y-t.y);
    if(l=0)then
    begin
      writeln(0);
      continue;
    end;
    if(l=1)and(e.x=t.x)and(e.y=t.y)then
    begin
      writeln(1);
      continue;
    end;
    if(cal[s.x,s.y]=0)or(cal[t.x,t.y]=0)then
    begin
      writeln(-1);
      continue;
    end;
    fillchar(vis,sizeof(vis),0);
    ans[1]:=dfs;
{
  for i:=1 to n do
  begin
    for j:=1 to m do write(vis[i,j],' ');writeln;
  end;
}
    fillchar(vis,sizeof(vis),0);
    l:=1;r:=1;q[1].x:=s.x;b:=false;
    q[1].y:=s.y;vis[s.x,s.y]:=1;
    while l<=r do
    begin
      now:=q[l];
      if(cal[now.x,now.y]=1)then
      begin
        if(a[now.x+1,now.y]=1)and(a[now.x,now.y+1]=1)
        and(a[now.x+1,now.y+1]=1)then
        begin
          if vis[now.x+1,now.y]=0then
          begin
            add(now.x+1,now.y,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
          if vis[now.x,now.y+1]=0then
          begin
            add(now.x,now.y+1,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
        end;//youxiafang
        if(a[now.x+1,now.y]=1)and(a[now.x,now.y-1]=1)
        and(a[now.x+1,now.y-1]=1)then
        begin
          if vis[now.x+1,now.y]=0then
          begin
            add(now.x+1,now.y,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
          if vis[now.x,now.y-1]=0then
          begin
            add(now.x,now.y-1,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
        end;//zuoxiafang
        if(a[now.x-1,now.y]=1)and(a[now.x,now.y-1]=1)
        and(a[now.x-1,now.y-1]=1)then
        begin
          if vis[now.x-1,now.y]=0then
          begin
            add(now.x-1,now.y,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
          if vis[now.x,now.y-1]=0then
          begin
            add(now.x,now.y-1,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
        end;//zuoshangfang
        if(a[now.x-1,now.y]=1)and(a[now.x,now.y+1]=1)
        and(a[now.x-1,now.y+1]=1)then
        begin
          if vis[now.x-1,now.y]=0then
          begin
            add(now.x-1,now.y,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
          if vis[now.x,now.y+1]=0then
          begin
            add(now.x,now.y+1,ans[l]+3);
            if(q[r].x=t.x)and(q[r].y=t.y)then
            begin
              b:=true;
              writeln(ans[l]+1);
              break;
            end;
          end;
        end;//youshangfang
      end;
      l:=l+1;
    end;
    if not b then writeln(-1);
  end;
close(input);close(output);
end.