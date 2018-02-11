program puzzle;
const
  dx:array[1..4]of integer=(1,-1,0,0);
  dy:array[1..4]of integer=(0,0,1,-1);
var
  n,m,i,j,q,ex,ey,sx,sy,tx,ty,max:longint;
  map:array[0..31,0..31]of 0..1;
  q7,q1,q2,q3,q4,q5,q6:array[1..8500000]of integer;
procedure bfs(x,y:longint);
var
  f,r,u,v,ii:longint;
  ok2:boolean;
begin
  f:=0;r:=1;
  q1[r]:=x;q2[r]:=y;q5[r]:=sx;q6[r]:=sy;
  q7[1]:=0;
  repeat
    inc(f);
    if q7[f]>max then
    begin
      writeln(-1);
      exit;
    end;
    for ii:=1 to 4 do
    begin
      u:=q1[f]+dx[ii];v:=q2[f]+dy[ii];
      if (u>0)and(u<=n)and(v<=m)and(v>0)and((u<>q3[f])or(v<>q4[f]))and(map[u,v]=1)then
      begin
       if (u=q5[f])and(v=q6[f])and(q1[f]=tx)and(q2[f]=ty)then
       begin
        writeln(q7[f]+1);
        exit;
       end;
       inc(r);
       q1[r]:=u;q2[r]:=v;
       q7[r]:=q7[f]+1;q3[r]:=q1[f];q4[r]:=q2[f];
       if (u<>q5[f])or(v<>q6[f])then
       begin
         q5[r]:=q5[f];q6[r]:=q6[f];
       end
       else if (u=q5[f])and(v=q6[f])then
       begin
         q5[r]:=q1[f];q6[r]:=q2[f];
       end;
      end;
    end;
  until(f=r);
  writeln(-1);
end;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  read(n,m,q);
  for i:=1 to n do
  for j:=1 to m do
  read(map[i,j]);
  max:=n*m;
  for i:=1 to q do
  begin
    read(ex,ey,sx,sy,tx,ty);
    bfs(ex,ey);
  end;
  close(output);
  close(input);
end.
