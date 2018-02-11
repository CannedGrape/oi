type aaa=record
     x1,x2,y1,y2,step:longint;
end;
const movex:array[1..4]of integer=(1,0,-1,0);
      movey:array[1..4]of integer=(0,1,0,-1);
var n,m,i,j,q,x:longint;
    mark:array[1..30,1..30]of boolean;
function gujia(x,y,tx,ty:longint):longint;
begin
  exit(sqr(tx-x)+sqr(ty-y))
end;
procedure work;
var ex,ey,sx,sy,tx,ty,xx,yy,ss,i,j,k,head,tail:longint;
    mark2:array[1..30,1..30]of boolean;

    link:array[1.. 100000]of aaa;
begin
  read(ex,ey,sx,sy,tx,ty);
  for i:=1 to n do
    for j:=1 to m do
      mark2[i,j]:=mark[i,j];



  for i:=1 to n do
    for j:=1 to m do
      begin
      if not mark[i,j] then continue;
      ss:=0;
      for k:=1 to 4 do
        begin
          xx:=i+movex[k];
          yy:=j+movey[k];
          if (xx>0)and(xx<=n)and(yy>0)and(yy<=m)and(mark[xx,yy]) then
            inc(ss);
        end;
      if ss<2 then mark2[i,j]:=false;
      end;
  if not mark2[tx,ty] then
    begin
      if not((tx=sx)and(ty=sy)) then
      writeln(-1)
      else writeln(0);
      exit;
    end;

  fillchar(link,sizeof(link),0);
  head:=0;tail:=1;
  with link[1] do
    begin
      x1:=sx;
      x2:=ex;
      y1:=sy;
      y2:=ey;
      step:=0;
    end;
  while head<tail do
    begin
      inc(head);
      for i:=1 to 4 do
        begin
            xx:=link[head].x2+movex[i];
            yy:=link[head].y2+movey[i];
            //if gujia(xx,yy,tx,ty)>gujia(link[head].x2,link[head].y2,tx,ty) then continue;
            if not mark[xx,yy] then continue;
            inc(tail);
            link[tail]:=link[head];
            with link[tail] do
              begin
                x2:=xx;
                y2:=yy;
                inc(step);
                if (x1=x2)and(y1=y2) then
                  begin
                    x1:=link[head].x2;
                    y1:=link[head].y2;
                  end;
                if (x1=tx)and(y1=ty) then
                  begin
                    writeln(step);
                    exit;
                  end;
              end;
        end;
    end;
end;
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  read(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(x);
        if x=1 then mark[i,j]:=true;
      end;
  for i:=1 to q do
    work;
  close(input);
  close(output);
end.