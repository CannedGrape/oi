const xx:array[1..4]of longint=(0,0,1,-1);
      yy:array[1..4]of longint=(1,-1,0,0);
var n,m,t,i,j:longint;
    map:array[0..31,0..31]of longint;
    hash:array[0..31,0..31,0..31,0..31]of boolean;
    q:array[0..900000]of record ex,ey,sx,sy,step:longint;end;
function solve:longint;
var ex,ey,sx,sy,tx,ty,dex,dey,dsx,dsy,head,tail,i:longint;
begin
  readln(ex,ey,sx,sy,tx,ty);
  if (sx=tx)and(sy=ty) then exit(0);
  fillchar(hash,sizeof(hash),false);
  hash[ex,ey,sx,sy]:=true;
  head:=0;
  tail:=1;
  q[1].ex:=ex;
  q[1].ey:=ey;
  q[1].sx:=sx;
  q[1].sy:=sy;
  q[1].step:=0;
  while head<tail do
  begin
    inc(head);
    for i:=1 to 4 do
    begin
      dex:=q[head].ex+xx[i];dey:=q[head].ey+yy[i];
      if (dex<0)or(dex>n)or(dey<0)or(dey>m) then continue;
      if map[dex,dey]=0 then continue;
      if (dex=q[head].sx)and(dey=q[head].sy) then
      begin
        dsx:=q[head].ex;dsy:=q[head].ey;
      end else
      begin
        dsx:=q[head].sx;dsy:=q[head].sy;
      end;
      if hash[dex,dey,dsx,dsy] then continue;
      if (dsx=tx)and(dsy=ty) then exit(q[head].step+1);
      inc(tail);
      q[tail].ex:=dex;q[tail].ey:=dey;
      q[tail].sx:=dsx;q[tail].sy:=dsy;
      q[tail].step:=q[head].step+1;
      hash[dex,dey,dsx,dsy]:=true;
    end;
  end;
  exit(-1);
end;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,t);
  for i:=1 to n do
    for j:=1 to m do read(map[i,j]);
  for i:=1 to t do writeln(solve);
  close(input);close(output);
end.
