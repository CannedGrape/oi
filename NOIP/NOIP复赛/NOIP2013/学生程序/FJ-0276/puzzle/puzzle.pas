const
  u:array[1..4,1..2] of longint
    =((0,1),(1,0),(0,-1),(-1,0));

var
  n,m,q,i,j,a,ac,cur,ax,ay,bx,by,cx,cy:longint;
  d:array[0..1000,1..3] of longint;
  vis,v:array[0..32,0..32] of boolean;
  way:array[0..1000,1..2] of longint;
  ra:array[0..32,0..32,1..2] of longint;

procedure bfs1;
  var h,t,i,x,y:longint;
  begin
    h:=0; t:=1;
    d[1,1]:=ax; d[1,2]:=ay;
    vis:=v; vis[ax,ay]:=false;
    while h<t do
    begin
      inc(h);
      for i:= 1 to 4 do
      begin
        x:=d[h,1]+u[i,1];
        y:=d[h,2]+u[i,2];
        if vis[x,y] then
        begin
          inc(t); vis[x,y]:=false;
          d[t,1]:=x; d[t,2]:=y;
          ra[x,y,1]:=d[h,1];
          ra[x,y,2]:=d[h,2];
          if (x=bx)and(y=by) then exit;
        end;
      end;
    end;
  end;

procedure bfs2(kkx,kky:longint);
  var h,t,i,kx,ky:longint;
  begin
    h:=0; t:=1;
    d[1,1]:=kkx; d[1,2]:=kky; d[1,3]:=0;
    vis:=v;
    vis[kkx,kky]:=false;
    vis[ax,ay]:=false;
    while h<t do
    begin
      inc(h);
      for i:= 1 to 4 do
      begin
        kx:=d[h,1]+u[i,1];
        ky:=d[h,2]+u[i,2];
        if vis[kx,ky] then
        begin
          inc(t); vis[kx,ky]:=false;
          d[t,1]:=kx; d[t,2]:=ky;
          d[t,3]:=d[h,3]+1;
          if (kx=cx)and(ky=cy) then
            begin cur:=d[t,3]; exit; end;
        end;
      end;
    end;
  end;

procedure work;
  var x,y,i,long,kx,ky:longint;
  begin
    fillchar(ra,sizeof(ra),0);
    fillchar(way,sizeof(way),0);
    bfs1;
    if vis[bx,by] then
      begin ac:=-1; exit; end;

    x:=bx; y:=by; long:=0;
    while (x<>ax)or(y<>ay) do
    begin
      inc(long);
      way[long,1]:=x; way[long,2]:=y;
      kx:=ra[x,y,1]; ky:=ra[x,y,2];
      x:=kx; y:=ky;
    end;

    ac:=long;
    for i:= long downto 1 do
    begin
      x:=way[i,1]; y:=way[i,2];
      bfs2(x,y);
      if (vis[cx,cy])or((ax=cx)and(ay=cy)) then
        begin ac:=-1; exit; end;
      inc(ac,cur);
      cx:=ax; cy:=ay;
      ax:=way[i,1]; ay:=way[i,2];
    end;
  end;

begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);
  fillchar(v,sizeof(v),0);
  read(n,m,q);
  for i:= 1 to n do
    for j:= 1 to m do
    begin
      read(a);
      if a=1 then v[i,j]:=true;
    end;

  for i:= 1 to q do
  begin
    read(cx,cy,ax,ay,bx,by);
    work;
    writeln(ac);
  end;
  close(input); close(output);
end.
