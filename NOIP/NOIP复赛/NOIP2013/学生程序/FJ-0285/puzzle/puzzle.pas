const
  direc:array[1..4,1..2] of integer=((0,1),(0,-1),(1,0),(-1,0));
var
  map:array[0..31,0..31] of boolean;
  t,i,j,n,m,q,ex,ey,sx,sy,tx,ty:integer;
  queue:array[0..1000000,1..5] of integer;
  flag:array[1..30,1..30,1..30,1..30] of boolean;

procedure bfs;
var
  head,tail:longint;
  i,mx,my,mmx,mmy,xx,yy,x,y,ans:integer;
begin

  fillchar(flag,sizeof(flag),true);
  queue[1,1]:=ex;
  queue[1,2]:=ey;
  queue[1,3]:=sx;
  queue[1,4]:=sy;
  queue[1,5]:=0;

  flag[ex,ey,sx,sy]:=false;
  head:=0;
  tail:=1;

  repeat
    inc(head);
    x:=queue[head,1];
    y:=queue[tail,2];
    mx:=queue[head,3];
    my:=queue[head,4];
    ans:=queue[head,5];

    for i:=1 to 4 do begin
      xx:=x+direc[i,1];
      yy:=y+direc[i,2];
      if (mx=xx) and (my=yy) then begin
        mmx:=x;
        mmy:=y;
      end else
      begin
        mmx:=mx;
        mmy:=my;
      end;

      if (mmx=tx) and (mmy=ty) then begin
        writeln(ans+1);
        exit;
      end;

      if map[xx,yy] and flag[xx,yy,mmx,mmy] then begin
        inc(tail);
        queue[tail,1]:=xx;
        queue[tail,2]:=yy;
        queue[tail,3]:=mmx;
        queue[tail,4]:=mmy;
        queue[tail,5]:=ans+1;
        flag[xx,yy,mmx,mmy]:=false;
      end;
    end;

  until head >= tail;

  writeln( -1 );
end;

begin

  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);

  readln( n,m,q );

  fillchar(map,sizeof(map),false);

  for i:=1 to n do begin
    for j:=1 to m do begin
      read(t);
      if t=1 then map[i,j]:=true;
    end;
    readln;
  end;

  for i:=1 to q do begin
    readln(ex,ey,sx,sy,tx,ty);
    bfs;
  end;

  close(input);
  close(output);

end.

