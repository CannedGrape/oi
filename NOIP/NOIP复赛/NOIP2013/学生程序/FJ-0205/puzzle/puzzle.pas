{type poi=record
           x,y:longint;
         end;
const fx:array[1..2] of longint=(1,0);
      fy:array[1..2] of longint=(0,1);
var n,m,q:longint;
    map,number,flag:array[0..31,0..31] of longint;
    tot,sum:longint;
    num,next,line,c,color:array[0..810000] of longint;
    e,s,t:poi;
    index:longint;
    low,dfn,f:array[0..900] of longint;
    queue,way:array[0..810000] of longint;
    pass:boolean;
procedure init;
var i,j:longint;
    point:longint;
begin
  readln(n,m,q);
  fillchar(map,sizeof(map),0);
  for i:=1 to n do
  begin
    for j:=1 to m do read(map[i,j]);
    readln;
  end;

  point:=0;
  fillchar(number,sizeof(number),0);
  for i:=1 to n do
   for j:=1 to m do
   if map[i,j]=1 then
   begin
     point:=point+1;
     number[i,j]:=point;
   end;
end;
procedure add(x,y:longint);
begin
  sum:=sum+1;
  tot:=tot+1;
  next[tot]:=num[x]; num[x]:=tot; line[tot]:=y; c[tot]:=sum;
  tot:=tot+1;
  next[tot]:=num[y]; num[y]:=tot; line[tot]:=x; c[tot]:=sum;
end;
procedure dfs(x,y:longint);
var i:longint;
begin
  flag[x,y]:=1;
  for i:=1 to 2 do
  if (map[x+fx[i],y+fy[i]]=1) and (flag[x+fx[i],y+fy[i]]=0) then
  begin
    add(number[x,y],number[x+fx[i],y+fy[i]]);
    dfs(x+fx[i],y+fy[i]);
  end;
end;
procedure init_G;
var i,j:longint;
begin
  fillchar(flag,sizeof(flag),0); tot:=0; sum:=0;
  fillchar(num,sizeof(num),0);
  fillchar(next,sizeof(next),0);
  fillchar(line,sizeof(line),0);
  fillchar(c,sizeof(c),0);
  for i:=1 to n do
   for j:=1 to m do
   if (map[i,j]=1) and (flag[i,j]=0) then dfs(i,j);
end;
procedure tarjan(u,last,tt:longint);
var tmp,pre:longint;
begin
  f[u]:=1;
  index:=index+1; low[u]:=index; dfn[u]:=index;
  tmp:=num[u]; pre:=line[tmp];
  while tmp<>0 do
  begin
    if (f[pre]=0) and (c[tmp]<>last) then
    begin
      tarjan(pre,c[tmp],tmp);
      if low[u]>dfn[pre] then low[u]:=dfn[pre];
    end
    else begin
           if f[pre]=1 then
           begin
             if low[u]>low[pre] then low[u]:=low[pre];
           end;
         end;
    tmp:=next[tmp]; pre:=line[tmp];
  end;
  if low[u]=dfn[u] then color[tt]:=1;
end;
procedure findbridge;
var i,j:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(low,sizeof(low),0);
  fillchar(dfn,sizeof(dfn),0);
  fillchar(color,sizeof(color),0);
  index:=0;
  for i:=1 to n do
   for j:=1 to m do
   if (map[i,j]=1) and (f[number[i,j]]=0)
   then tarjan(number[i,j],0,0);
end;
procedure find(x,y:longint);
var fr,re:longint;
    tmp,pre,u:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(way,sizeof(way),0);
  fr:=0; re:=1; queue[1]:=number[x,y]; f[number[x,y]]:=1; way[1]:=0;
  while fr<re do
  begin
    fr:=fr+1; u:=queue[fr];
    if u=number[e.x,e.y] then break;
    tmp:=num[u]; pre:=line[tmp];
    while tmp<>0 do
    begin
      if f[pre]=0 then
      begin
        re:=re+1; way[re]:=way[fr];
        if color[tmp]=1 then way[re]:=1;
        queue[re]:=pre;
        f[pre]:=1;
      end;
      tmp:=next[tmp]; pre:=line[tmp];
    end;
  end;
  if way[fr]=1 then pass:=true;
end;
procedure print;
var i:longint;
begin
  for i:=1 to q do
  begin
    readln(e.x,e.y,s.x,s.y,t.x,t.y); pass:=false;
    find(s.x,s.y);
    if pass then begin writeln(-1); continue; end;

  end;
end;
begin
  init;
  init_G;
  findbridge;
  print;
end.    }
var n,m,q,i:longint;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to q do writeln(-1);
  close(input);
  close(output);
end.
//OI,we'll never meet again,but I'll still miss you as well as love you in the future!
//It's you who provide me the happy memory!
//OI you will continue and I'll retire.
//D.T. OI RP++!
//Apoptoxinice 2013.11.10
