program puzzle;
  const v:array[1..4,1..2]of longint=((0,1),(1,0),(0,-1),(-1,0));
  var c:array[1..30,1..30,1..30,1..30]of boolean;
      b:array[1..30,1..30,1..30,1..30]of longint;
      map:array[1..30,1..30]of longint;
      x,y,x1,y1:array[1..810000]of longint;
      i,j,m,n,z,ex,ey,sx,sy,ox,oy,o,q:longint;
  procedure bfs;
  var i,j,h,t,tx,ty,kx,ky:longint;
  begin
    h:=0;t:=1;
    x[1]:=ex;y[1]:=ey;x1[1]:=sx;y1[1]:=sy;b[sx,sy,ex,ey]:=0;
    repeat
      inc(h);
      for i:=1 to 4 do
      begin
        tx:=x[h]+v[i,1];ty:=y[h]+v[i,2];
        if (tx>=1)and(tx<=m)and(ty>=1)and(ty<=n)and(map[tx,ty]<>0) then
        begin
          kx:=x1[h];ky:=y1[h];
          if (tx=x1[h])and(ty=y1[h])then
          begin
            kx:=x[h];ky:=y[h];
          end;
          if c[kx,ky,tx,ty]=true then
          begin
            inc(t);
            x[t]:=tx;y[t]:=ty;x1[t]:=kx;y1[t]:=ky;c[kx,ky,tx,ty]:=false;
            b[kx,ky,tx,ty]:=b[x1[h],y1[h],x[h],y[h]]+1;
            if (kx=ox)and(ky=oy) then
            begin
              writeln(b[kx,ky,tx,ty]);
              o:=1;
              exit;
            end;
          end;
        end;
      end;
    until h>=t;
  end;
  begin
    assign(input,'puzzle.in');assign(output,'puzzle.out');
    reset(input);rewrite(output);
    read(m,n,q);
    for i:=1 to m do
    for j:=1 to n do read(map[i,j]);
    for i:=1 to q do
    begin
      fillchar(c,sizeof(c),true);
      read(ex,ey,sx,sy,ox,oy);
      if (sx=ox)and(sy=oy) then writeln(0)
      else begin
        c[sx,sy,ex,ey]:=false;
        o:=0;
        bfs;
        if o=0 then writeln(-1);
      end;
    end;
    close(input);close(output);
  end.
