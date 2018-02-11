type
  shu=0..1;
var
  a1:array [1..4] of integer=(0,0,-1,1);
  a2:array [1..4] of integer=(1,-1,0,0);
  ll:array [1..100000] of record
    zx,zy,bx,by,x,y,bs:integer;
  end;
  n,m,q,i,j,r,ex,ey,tx,ty,sx,sy,head,tail,x1,y1:longint;
  a:array [1..30,1..30] of shu;
  s:array [1..500] of longint;
  bo:boolean;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
  for j:=1 to m do read(a[i,j]);
  for r:=1 to q do
  begin
    bo:=false;
    read(ex,ey,sx,sy,tx,ty);
    head:=0;
    tail:=1;
    ll[1].zx:=ex;
    ll[1].zy:=ey;
    ll[1].x:=sx;
    ll[1].y:=sy;
    repeat
      inc(head);
      for i:=1 to 4 do
      if (a1[i]<>ll[head].bx)or(a2[i]<>ll[head].by) then
      begin
        x1:=ll[head].zx+a1[i];
        y1:=ll[head].zy+a2[i];
        if (x1>0)and(x1<=n)and(y1>0)and(y1<=m)and(a[x1,y1]<>0) then
        begin
          inc(tail);
          ll[tail].bs:=ll[head].bs+1;
          ll[tail].zx:=x1;
          ll[tail].zy:=y1;
          ll[tail].bx:=-a1[i];
          ll[tail].by:=-a2[i];
          if (x1=ll[head].x)and(y1=ll[head].y) then
          begin
            ll[tail].x:=ll[head].zx;
            ll[tail].y:=ll[head].zy;
            bo:=true;
          end else
          begin
            ll[tail].x:=ll[head].x;
            ll[tail].y:=ll[head].y;
          end;
          if (ll[tail].x=tx)and(ll[tail].y=ty) then
          begin
            s[r]:=ll[tail].bs;
            break;
          end;
          if (ll[tail].x=sx)and(ll[tail].y=sy)and(bo=true) then dec(tail);
        end;
      end;
    until (s[r]<>0)or(head=tail);
  end;
  for i:=1 to q do if s[i]<>0 then writeln(s[i]) else writeln(-1);
  close(input);
  close(output);
end.
