const dir:Array[1..4,1..2]of longint=((0,1),(0,-1),(1,0),(-1,0));
type arr=record
    x,y,z:longint;
end;
var map:array[0..30,0..30]of longint;
    f:array[0..1000000]of arr;
    v:array[0..30,0..30]of boolean;
    n,m,t,ans,i,j,ex,ey,tx,ty,sx,sy,x,y,z:longint;
    flag:boolean;
procedure bfs(x,y:longint);
var head,tail,i,xx,yy:longint;
begin
  head:=0;tail:=1;
  fillchar(v,sizeof(v),false);
  v[x,y]:=true;
  f[1].x:=x;
  f[1].y:=y;
  f[1].z:=0;
  while head<tail do
    begin
      inc(head);
      for i:=1 to 4 do
        begin
          xx:=f[head].x+dir[i,1];
          yy:=f[head].y+dir[i,2];
          if (xx<1) or (xx>n) or (yy<1) or (yy>m) then continue;
          if (v[xx,yy]) then continue;
          if (map[xx,yy]=0) then continue;
          if (xx=sx) and (yy=sy) then
            begin
              sx:=f[head].x;
              sy:=f[head].y;
            end;
          if (xx=tx) and (yy=ty) then
            begin
              ans:=f[head].z+1;
              exit;
            end;
          inc(tail);
          f[tail].x:=xx;
          f[tail].y:=yy;
          f[tail].z:=f[head].z+1;
        end;
    end;
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,t);
  for i:=1 to n do
    for j:=1 to m do
      read(map[i,j]);
  for i:=1 to t do
    begin
      ans:=-1;
      readln(ex,ey,sx,sy,tx,ty);
      bfs(ex,ey);
      if ans<>-1 then
        begin
          flag:=false;
         for j:=1 to 4 do
           begin
             x:=tx+dir[j,1];
             y:=ty+dir[j,2];
             if (x=sx) and (y=sy) then
                 begin
                   ans:=ans+1;
                   flag:=true;
                 end;
           end;
        end;
      if flag then writeln(ans)
      else writeln(-1);
    end;
  close(input);close(output);
end.
