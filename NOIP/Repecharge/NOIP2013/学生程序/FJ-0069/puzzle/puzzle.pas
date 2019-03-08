program p3;
const v1:array[1..4]of longint=(1,0,-1,0);
      v2:array[1..4]of longint=(0,1,0,-1);
type lr=record
       e,s,eex,eey,ssx,ssy,ans:longint;
     end;
var i,j,sx,sy,ex,ey,tx,ty,n,m,qq,finalsum:longint;
    a:array[0..32,0..32]of longint;
    f:array[0..910,0..910]of boolean;
    q:array[0..1000000]of lr;
function sum(x,y:longint):longint;
begin
  sum:=(x-1)*m+y;
end;
procedure bfs;
var h,t,i,x,y,x1,y1,linux:longint;
begin
  q[1].e:=sum(ex,ey);q[1].s:=sum(sx,sy);
  q[1].eex:=ex;q[1].eey:=ey;
  q[1].ssx:=sx;q[1].ssy:=sy;
  f[q[1].e,q[1].s]:=true;
  h:=0;t:=1;
  while h<t do
  begin
    inc(h);
    for i:=1 to 4 do
    begin
      x:=q[h].eex+v1[i];
      y:=q[h].eey+v2[i];
      if(a[x,y]=1)then
      begin
        if(x=q[h].ssx)and(y=q[h].ssy)then
        begin
          x1:=q[h].eex;y1:=q[h].eey;
        end else
        begin
          x1:=q[h].ssx;y1:=q[h].ssy;
        end;
        if(not f[sum(x,y),sum(x1,y1)])then
        begin
          inc(t);
          q[t].e:=sum(x,y);q[t].s:=sum(x1,y1);
          f[q[t].e,q[t].s]:=true;
          q[t].eex:=x;q[t].eey:=y;
          q[t].ssx:=x1;q[t].ssy:=y1;
          q[t].ans:=q[h].ans+1;
          linux:=abs(x1-x)+abs(y1-y);
          if(linux=1)and(q[t].e=finalsum)then
          begin
            writeln(q[t].ans+1);exit;
          end;
          if q[t].s=finalsum then
          begin
            writeln(q[t].ans);exit;
          end;
        end;
      end;
    end;
  end;
  writeln('-1');
end;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,qq);
  for i:=1 to n do
  for j:=1 to m do
    read(a[i,j]);
  for i:=1 to qq do
  begin
    readln(ex,ey,sx,sy,tx,ty);
    if(a[ex,ey]=0)or(a[sx,sy]=0)or(a[tx,ty]=0)then
    begin
      writeln('-1');
      continue;
    end;
    finalsum:=sum(tx,ty);
    fillchar(f,sizeof(f),false);
    bfs;
  end;
  close(input);close(output);
end.