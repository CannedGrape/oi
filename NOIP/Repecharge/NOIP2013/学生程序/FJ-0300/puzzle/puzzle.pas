const fx:array[1..4,1..2]of longint=((1,0),(-1,0),(0,1),(0,-1));
var n,m,p,i,j,ex,ey,sx,sy,tx,ty:longint;
    map:array[0..31,0..31]of longint;
    g:array[1..1000000]of record
                          wx,wy,qx,qy,time:longint;
                         end;
procedure bfs;
  var top,bot,k,x,y,nx,ny:longint;
  begin
    fillchar(g,sizeof(g),0);
    top:=0;bot:=1;
    g[1].wx:=ex;g[1].wy:=ey;
    g[1].qx:=sx;g[1].qy:=sy;
    g[1].time:=0;
    repeat
      inc(top);
      if top>1000000 then top:=1;
      x:=g[top].wx;y:=g[top].wy;
      for k:=1 to 4 do
        begin
          nx:=x+fx[k,1];
          ny:=y+fx[k,2];
          if (map[nx,ny]<>0)then
            begin
              inc(bot);
              if bot>1000000 then bot:=1;
              g[bot].wx:=nx;g[bot].wy:=ny;
              g[bot].time:=g[top].time+1;
              if (nx=g[top].qx)and(ny=g[top].qy) then
                begin
                  g[bot].qx:=x;g[bot].qy:=y;
                  if (g[bot].qx=tx)and(g[bot].qy=ty) then
                    begin
                      writeln(g[bot].time);
                      exit;
                    end;
                end
              else
                begin
                  g[bot].qx:=g[top].qx;g[bot].qy:=g[top].qy;
                end;
            end;
        end;
    until bot=top;
    writeln(-1);
  end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,p);
  fillchar(map,sizeof(map),0);
  for i:=1 to n do
    begin
      for j:=1 to m do read(map[i,j]);
      readln;
    end;
  for i:=1 to p do
    begin
      readln(ex,ey,sx,sy,tx,ty);
      bfs;
    end;
  close(input);close(output);
end.
