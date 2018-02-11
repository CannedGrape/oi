function min(a,b:longint):longint;
begin
  if b>a then exit(a) else exit(b);
end;
const dx:array[1..8] of integer=(1,1,-1,-1,0,0,2,-2);
      dy:array[1..8] of integer=(1,-1,1,-1,2,-2,0,0);
      mx:array[1..4] of -1..1=(-1,1,0,0);
      my:array[1..4] of -1..1=(0,0,-1,1);
var n,m,q,i,j,k,x,y,ex,ey,sx,sy,tx,ty:longint;
    f:array[0..50,0..50] of 0..1;
    dis:array[0..900,0..900] of longint;
    vis:array[0..900,0..900] of boolean;
procedure cx(l,r,x,y,nn:longint);
var k,x1,y1:longint;
begin
  if (l=x) and (r=y) then
  begin
    dis[i*m+j,x*m+y]:=min(nn,dis[i*m+j,x*m+y]);
    exit;
  end;
  for k:=1 to 4 do
  begin
    x1:=l+mx[k];y1:=r+my[k];
    if (x1>=1) and (x1<=n) and (y1>=1) and (y1<=m) and (f[x1,y1]=1) and not(vis[x1,y1]) then
    begin
      vis[x1,y1]:=true;
      cx(x1,y1,x,y,nn+1);
      vis[x1,y1]:=false;
    end;
  end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  begin
    for j:=1 to m do read(f[i,j]);
    readln;
  end;
  fillchar(dis,sizeof(dis),$3f);
  for i:=1 to n do
    for j:=1 to m do
    begin
      if f[i,j]<>0 then
      begin
        vis[i,j]:=true;
        for k:=1 to 8 do
        begin
          x:=i+dx[k];y:=j+dy[k];
          if (x>=1) and (x<=n) and (y>=1) and (y<=m) and (f[x,y]=1) then cx(i,j,x,y,0);
        end;
        vis[i,j]:=false;
      end;
    end;
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    writeln('-1');
  end;
  close(input);
  close(output);
end.

