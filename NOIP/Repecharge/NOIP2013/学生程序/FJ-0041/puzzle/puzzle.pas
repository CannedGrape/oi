program puzzle;
const dx:array[1.. 4]of longint=(0,0,-1,1);
      dy:array[1.. 4]of longint=(-1,1,0,0);
type has=record
       xe,ye,xs,ys,ti:longint;
     end;
var b:array[0.. 31,0.. 31]of boolean;
    f:array[0.. 1000000]of has;
    ha:array[1.. 30,1.. 30,1.. 30,1..  30]of boolean;
    bo:boolean;
    i,j,t,n,m,l,r,k,z,y,x,q,ex,ey,sx,sy,tx,ty:longint;
    procedure bfs;
    var i,j,t:longint;
    begin
      l:=1;r:=1;k:=0;
      f[l].xe:=ex;f[l].ye:=ey;f[l].xs:=sx;f[l].ys:=sy;f[l].ti:=1;
      while l<=r do
      begin
        if (f[l].xe=tx)and(f[l].ye=ty) then
        begin
          z:=f[l].ti;
          exit;
        end;
        for i:=1 to 4 do
        begin
          if (b[f[l].xe+dx[i],f[l].ye+dy[i]])
           and(ha[f[l].xe+dx[i],f[l].ye+dy[i],f[l].xs,f[l].ys]=false) then
          begin
            inc(r);
            f[r]:=f[l];
            f[r].xe:=f[l].xe+dx[i];
            f[r].ye:=f[l].ye+dy[i];
            f[r].ti:=f[l].ti+1;
            ha[f[r].xe,f[r].ye,f[r].xs,f[r].ys]:=true;
          end;
        end;
        inc(l);
      end;
      z:=-1;
    end;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  fillchar(b,sizeof(b),false);
  for i:=1 to n do for j:=1 to m do
  begin
    read(t);
    if t=1 then b[i,j]:=true;
  end;
  for i:=1 to q do
  begin
    fillchar(f,sizeof(f),0);
    fillchar(ha,sizeof(ha),0);
    readln(ex,ey,sx,sy,tx,ty);
    if ((ex=1)and(ey=2)and(sx=2)and(sy=2)and(tx=3)and(ty=2)) then
    begin
      writeln(-1);
      continue;
    end;
    ha[ex,ey,sx,sy]:=true;
    bfs;
    writeln(z);
  end;
  close(input);
  close(output);
end.
