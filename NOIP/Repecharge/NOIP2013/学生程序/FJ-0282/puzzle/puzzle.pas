program exl;
const lx:array[1..4] of -1..1=(-1,0,0,1);
      ly:array[1..4] of -1..1=(0,-1,1,0);
      maxn=1000003;
      maxv=maxlongint div 2;
var q1,i,j,m,n,k,q:longint;
    map:array[0..31,0..31] of longint;
    ex,ey,sx,sy,tx,ty:longint;
    w:boolean;
    a:array[0..maxn] of record
     kx,ky,nx,ny:longint
    end;
    dis:array[0..31,0..31,0..31,0..31] of longint;
    use:array[0..31,0..31,0..31,0..31] of boolean;
function work:longint;
var l,r,x,y,i,j,k,x1,y1:longint;
begin
 for i:=1 to n do
  for j:=1 to m do
   for x:=1 to n do
    for y:=1 to m do
     begin
      dis[i,j,x,y]:=maxv;
      use[i,j,x,y]:=false;
     end;
 l:=0;r:=1;
 a[r].kx:=ex;a[r].ky:=ey;
 a[r].nx:=sx;a[r].ny:=sy;
 dis[ex,ey,sx,sy]:=0;
 use[ex,ey,sx,sy]:=true;
 while l<>r do
  begin
   inc(l);
   if l>maxn then l:=1;
   for j:=1 to 4 do
    begin
     x:=a[l].kx-lx[j];
     y:=a[l].ky-ly[j];
     if map[x,y]<=0 then continue;
     x1:=a[l].nx;
     y1:=a[l].ny;
     if (x=x1)and(y=y1) then
      begin
       x1:=a[l].kx;
       y1:=a[l].ky;
      end;
     if (x>0)and(y>0)and(x<=n)and(y<=m) then
      if dis[a[l].kx,a[l].ky,a[l].nx,a[l].ny]+1<dis[x,y,x1,y1] then
       begin
        dis[x,y,x1,y1]:=dis[a[l].kx,a[l].ky,a[l].nx,a[l].ny]+1;
        if (x1=tx)and(y1=ty) then exit(dis[x,y,x1,y1]);
        if not use[x,y,x1,y1] then
         begin
          inc(r);
          if r>maxn then r:=1;
          a[r].kx:=x;
          a[r].ky:=y;
          a[r].nx:=x1;
          a[r].ny:=y1;
          use[x,y,x1,y1]:=true;
        end;
       end;
    end;
   use[a[l].kx,a[l].ky,a[l].nx,a[l].ny]:=false;
  end;
 exit(-1);
end;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
    read(map[i,j]);
  for i:=1 to n do
   for  j:=1 to m do
    if map[i,j]=1 then
    begin
     q1:=0;
     for k:=1 to 4 do
      q1:=q1+abs(map[i+lx[k],j+ly[k]]);
     if q1<=1 then map[i,j]:=-1;
    end;
  for i:=1 to q do
   begin
    read(ex,ey,sx,sy,tx,ty);
    if (sx=tx)and(sy=ty) then
     begin
      writeln(0);
      continue;
     end;
    if (ex=tx)and(ey=ty) then
     begin
      w:=false;
      for k:=1 to 4 do
       if (sx+lx[k]=tx)and(sy+ly[k]=ty) then
        begin
         w:=true;
         break;
        end;
     if w then
      begin
       writeln(1);
       continue;
      end;
    end;
    if (map[tx,ty]<=0)or(map[sx,sy]<=0) then
     begin
      writeln(-1);
      continue;
     end;
    writeln(work);
   end;
  close(input);
  close(output);
end.
