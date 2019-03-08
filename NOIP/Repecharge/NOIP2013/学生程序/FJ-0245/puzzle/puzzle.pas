var
  f:array[1..30,1..30,1..30,1..30]of longint;
  a:array[0..31,0..31]of integer;
  t:array[1..810000,1..4]of integer;
  n,m,q,i,j,ex,ey,sx,sy,tx,ty,k:integer;
  px:array[1..4]of integer=(-1,1,0,0);
  py:array[1..4]of integer=(0,0,-1,1);
  head,tail,ans:longint;
  flag:boolean;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);

  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to n do begin a[i,0]:=0;a[i,m+1]:=0;end;
  for j:=1 to m do begin a[0,j]:=0;a[n+1,j]:=0;end;
  for q:=1 to q do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    fillchar(f,sizeof(f),0);
    flag:=false;
    head:=1;tail:=1;
    t[1,1]:=ex;
    t[1,2]:=ey;
    t[1,3]:=sx;
    t[1,4]:=sy;
    repeat
      ex:=t[head,1];
      ey:=t[head,2];
      for k:=1 to 4 do
      begin
        inc(ex,px[k]);
        inc(ey,py[k]);
        sx:=t[head,3];
        sy:=t[head,4];
        if(ex=sx)and(ey=sy)then
        begin
          sx:=t[head,1];
          sy:=t[head,2];
        end;
        if(a[ex,ey]=1)and(f[ex,ey,sx,sy]=0)then
        begin
          inc(tail);
          if(sx=tx)and(sy=ty)then flag:=true;
          t[tail,1]:=ex;
          t[tail,2]:=ey;
          t[tail,3]:=sx;
          t[tail,4]:=sy;
          f[ex,ey,sx,sy]:=f[t[head,1],t[head,2],t[head,3],t[head,4]]+1;
          if flag then break;
        end;
        dec(ex,px[k]);dec(ey,py[k]);
      end;
      if flag then break;
      inc(head);
    until head>tail;
    if flag then writeln(f[ex,ey,tx,ty])
    else writeln(-1);
  end;

  close(input);close(output);
end.