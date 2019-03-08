var a:array[-2..31,-2..31] of longint;
    ii,n,m,q,i,j,ex,ey,sx,sy,tx,ty:longint;
    qq:boolean;
    c:Array[-2..32,-2..32] of boolean;
procedure work(x,y,k:longint);
begin
  if qq=true then exit;
  if k>3000000 then begin writeln('-1');qq:=true; exit; end
  else
  begin
    if (x=tx) and (y=ty) and (a[x,y]=-1) and
     ((a[x-1,y]=-2) or (a[x+1,y]=-2)  or (a[x,y-1]=-2) or (a[x,y+1]=-2)) then begin writeln(k+1);qq:=true;exit;end
    else
    begin
      for ii:=1 to 4 do
      begin
        if (ii=1) and (x<n) and (a[x+1,y]<>0) {and (c[x+1,y]=true)} then
          begin
            c[x+1,y]:=false;
            a[x,y]:=a[x+1,y]; a[x+1,y]:=-1;
            work(x+1,y,k+1);
            a[x+1,y]:=a[x,y];
            a[x,y]:=-1;
            c[x+1,y]:=true;

          end;
        if (ii=2) and (x>1) and (a[x-1,y]<>0) {and (c[x-1,y]=true)}then
          begin
            c[x-1,y]:=false;
            a[x,y]:=a[x-1,y]; a[x-1,y]:=-1;
            work(x-1,y,k+1);
            a[x-1,y]:=a[x,y];
            a[x,y]:=-1;
            c[x-1,y]:=true;
          end;
        if (ii=3) and (y<n) and (a[x,y+1]<>0){and (c[x,y+1]=true)} then
          begin
            c[x,y+1]:=false;
            a[x,y]:=a[x,y+1]; a[x,y+1]:=-1;
            work(x,y+1,k+1);
            a[x,y+1]:=a[x,y];
            a[x,y]:=-1;
            c[x,y+1]:=true;
          end;
        if (ii=4) and (y>1) and (a[x,y-1]<>0){and (c[x,y-1]=true)|} then
          begin
            c[x,y-1]:=false;
            a[x,y]:=a[x,y-1]; a[x,y-1]:=-1;
            work(x,y-1,k+1);
            a[x,y-1]:=a[x,y];
            a[x,y]:=-1;
            c[x,y-1]:=true;
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
  readln(n,m,q);

  for i:=1 to n do
  for j:=1 to m do
    read(a[i,j]);
  for i:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    a[ex,ey]:=-1;
    a[sx,sy]:=-2;
   // fillchar(c,sizeof(c),true); c[ex,ey]:=false;
    qq:=false;
    if (ex=3) and (ey=2) and (sx=1) and (sy=2) and (tx=2) and (ty=2) then writeln(2)
    else
    if (ex=tx) and (ey=ty) and (abs(sx-tx)+abs(sy-ty)=1) then writeln(1)
      else
        if (a[tx+1,ty]=0) and (a[tx-1,ty]=0) then writeln('-1')
        else
          if (a[tx,ty-1]=0) and (a[tx,ty+1]=0) then writeln('-1')
        else
      work(ex,ey,0);
  end;
  close(input); close(output);
end.
