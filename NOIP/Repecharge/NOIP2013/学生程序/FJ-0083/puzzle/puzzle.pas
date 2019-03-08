program puzzle;
const maxn=30;maxm=30;maxq=500;inv=100000;
dx:array[1..4]of longint=(1,-1,0,-1);
dy:array[1..4]of longint=(0,0,1,0);
type node=record
  x,y:longint;
end;
var n,m,qt,temp,total,ans,i,j,k:longint;
map:array[0..maxn+1,0..maxn+1]of boolean;

e,s,t:node;

visited:array[1..30,1..30,1..30,1..30]of boolean;

dis:array[0..maxn+1,0..maxm+1]of longint;
q:array[1..maxn*maxm]of node;
now,aim:node;
head,tail:longint;


procedure dfs(step:longint);
var b_e,b_s:node;
te,ts:node;i,j,bak:longint;

p,dis2,index:array[1..4]of longint;
begin
  b_e:=e;
  b_s:=s;
  bak:=total;

  fillchar(dis,sizeof(dis),65);
  dis[e.x,e.y]:=0;
  q[1]:=e;
  head:=1;tail:=1;
  while head<=tail do begin
    now:=q[head];
    for i:=1 to 4 do begin
      aim:=now;
      inc(aim.x,dx[i]);
      inc(aim.y,dy[i]);
      if ((aim.x=s.x)and(aim.y=s.y))or(not(map[aim.x,aim.y])) then continue;
      if dis[aim.x,aim.y]>dis[now.x,now.y]+1 then begin
        dis[aim.x,aim.y]:=dis[now.x,now.y]+1;
        inc(tail);
        q[tail]:=aim;
      end;
    end;
    inc(head);
  end;
  for i:=1 to 4 do begin
    aim:=s;
    inc(aim.x,dx[i]);
    inc(aim.y,dy[i]);
    if dis[aim.x,aim.y]<inv then
      p[i]:=dis[aim.x,aim.y]
    else
      p[i]:=-1;
    dis2[i]:=abs(aim.x-t.x)+abs(aim.y-t.y);
    index[i]:=i;
  end;

  for i:=1 to 3 do
    for j:=i+1 to 4 do begin
      if dis2[i]>dis2[j] then begin
        temp:=dis2[i];dis2[i]:=dis2[j];dis2[j]:=temp;
        temp:=index[i];index[i]:=index[j];index[j]:=temp;
        temp:=p[i];p[i]:=p[j];p[j]:=temp;
      end;
    end;

  te:=e;
  ts:=s;
  for i:=1 to 4 do
    if p[i]>=0 then begin
      s:=ts;
      inc(s.x,dx[index[i]]);
      inc(s.y,dy[index[i]]);
      e:=ts;
      inc(total,p[i]+1);
      if not(visited[e.x,e.y,s.x,s.y]) then begin
        visited[e.x,e.y,s.x,s.y]:=true;
        if (s.x=t.x)and(s.y=t.y) then begin
          if total<ans then ans:=total;
        end
        else begin
          if total<ans then dfs(step+1);
        end;
      end;
      dec(total,p[i]+1);
    end;

  total:=bak;
  s:=b_s;
  e:=b_e;
end;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);

  read(n,m,qt);
  for i:=1 to n do
    for j:=1 to m do begin
      read(temp);
      if temp=1 then map[i,j]:=true;
    end;
  while qt>0 do begin
    ans:=inv;total:=0;
    fillchar(visited,sizeof(visited),#0);
    read(e.x,e.y,s.x,s.y,t.x,t.y);
    visited[e.x,e.y,s.x,s.y]:=true;
    dfs(1);
    if ans<inv then
      writeln(ans)
    else
      writeln(-1);
    dec(qt);
  end;

  close(input);close(output);
end.
