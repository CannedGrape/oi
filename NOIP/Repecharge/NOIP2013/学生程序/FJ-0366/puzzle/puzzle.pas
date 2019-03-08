const dx:array[1..4]of -1..1=(-1,0,1,0);
      dy:array[1..4]of -1..1=(0,-1,0,1);
var i,j,k,temp,x1,x2,x3,y1,y2,y3,n,m,p,tx,ty:longint;
    a:array[0..30,0..30] of boolean;
    d:array[1..10000,1..3] of longint;
    dl:array[1..50000,1..4] of longint;
    ans:Array[0..30,0..30,0..30,0..30] of longint;
    now:Array[0..30,0..30,0..30,0..30] of boolean;
    dis:array[0..30,0..30] of longint;

procedure bfs(q,w,x,y:longint);
var i,j,k,t,h,tx,ty:longint;
begin
  a[q,w]:=false;
  for i:=1 to n do
    for j:=1 to m do
      dis[i,j]:=9999999;
  h:=1;t:=1;
  d[1,1]:=x;d[1,2]:=y;d[1,3]:=0;
  while h<=t do
    begin
      for i:=1 to 4 do
        begin
          tx:=d[h,1]+dx[i];
          ty:=d[h,2]+dy[i];
          if (tx>0)and(tx<=m)and(ty>0)and(ty<=m)and(dis[tx,ty]=9999999) then
            if a[tx,ty] then
            begin
              inc(t);
              dis[tx,ty]:=d[h,3]+1;
              d[t,1]:=tx;d[t,2]:=ty;
              d[t,3]:=d[h,3]+1;
            end;
        end;
      inc(h);
    end;
  a[q,w]:=true;
end;

function pd:boolean;
var i,j:longint;
begin
  bfs(x2,y2,x1,y1);
  if dis[x3,y3]=9999999 then exit(true);
  exit(false);
end;

procedure spfa;
var i,j,k,t,h,tx,ty:longint;
begin
  h:=1;t:=0;
  fillchar(now,sizeof(now),false);
  for i:=1 to n do
    for j:=1 to m do
      for tx:=1 to n do
        for ty:=1 to m do ans[i,j,tx,ty]:=9999999;
  for i:=1 to 4 do
    begin
    tx:=x2+dx[i];ty:=y2+dy[i];
    if (tx>0)and(tx<=n)and(ty>0)and(ty<=m)and(dis[tx,ty]<>9999999) then
      begin
        inc(t);
        dl[t,1]:=x2;dl[t,2]:=y2;
        dl[t,3]:=tx;dl[t,4]:=ty;
        ans[x2,y2,tx,ty]:=dis[tx,ty];
        now[x2,y2,tx,ty]:=true;
      end;
    end;
  while h<=t do
    begin
      bfs(dl[t,1],d[t,2],dl[t,3],dl[t,4]);
      for i:=1 to 4 do
        begin
          tx:=dl[h,1]+dx[i];ty:=dl[h,2]+dy[i];
          if (tx>0)and(tx<=n)and(ty>0)and(ty<=m) then
            if ans[tx,ty,dl[h,1],dl[h,2]]>ans[dl[h,1],dl[h,2],dl[h,3],dl[h,4]]+dis[tx,ty]+1 then
                 begin
                   ans[tx,ty,dl[h,1],dl[h,2]]:=ans[dl[h,1],dl[h,2],dl[h,3],dl[h,4]]+dis[tx,ty]+1;
                   if not now[tx,ty,dl[h,1],dl[h,2]] then
                     begin
                       inc(t);
                       dl[t,1]:=tx;
                       dl[t,2]:=ty;
                       dl[t,3]:=dl[h,1];
                       dl[t,4]:=dl[h,2];
                       now[tx,ty,dl[h,1],dl[h,2]]:=true;
                     end;
                 end;
        end;
      now[dl[h,1],d[h,2],dl[h,3],dl[h,4]]:=false;
      inc(h);
    end;
end;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,p);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(temp);
          if temp=1 then a[i,j]:=true;
        end;
      readln;
    end;
  for i:=1 to p do
    begin
      readln(x1,y1,x2,y2,x3,y3);
      if pd then begin writeln(-1); continue; end;
      spfa;
      temp:=maxlongint;
      for j:=1 to 4 do
        begin
          tx:=x3+dx[j];ty:=y3+dy[j];
          if (tx>0)and(tx<=n)and(ty>0)and(ty<=m) then
            if ans[x3,y3,tx,ty]<temp then temp:=ans[x3,y3,tx,ty];
        end;
      if temp=9999999 then writeln(-1) else writeln(temp);
    end;
  close(input);close(output);
end.