type bian=record
            x,y,z:longint;
          end;

var n,m:longint;
    e:array[0..50001] of bian;
    father:array[0..10001] of longint;
    tot:longint;
    num,next,line,c:array[0..100001] of longint;
    flag:array[0..10001] of longint;
    ans:array[0..1001,0..1001] of longint;
procedure init;
var i:longint;
begin
  readln(n,m);
  for i:=1 to m do readln(e[i].x,e[i].y,e[i].z);
end;
procedure qsort(l,r:longint);
var i,j:longint;
    t:bian;
begin
  i:=l; j:=r; t:=e[i];
  while i<j do
  begin
    while (i<j) and (t.z>=e[j].z) do j:=j-1;
    if i<j then begin e[i]:=e[j]; i:=i+1; end;
    while (i<j) and (t.z<=e[i].z) do i:=i+1;
    if i<j then begin e[j]:=e[i]; j:=j-1; end;
  end;
  e[i]:=t; i:=i+1; j:=j-1;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;
function getfather(x:longint):longint;
begin
  if x<>father[x] then father[x]:=getfather(father[x]);
  exit(father[x]);
end;
procedure add(i:longint);
begin
  tot:=tot+1;
  next[tot]:=num[e[i].x]; num[e[i].x]:=tot; line[tot]:=e[i].y; c[tot]:=e[i].z;
  tot:=tot+1;
  next[tot]:=num[e[i].y]; num[e[i].y]:=tot; line[tot]:=e[i].x; c[tot]:=e[i].z;
end;
procedure kruscal;
var i:longint;
    fa,fb:longint;
begin
  qsort(1,m); tot:=0;
  fillchar(num,sizeof(num),0);
  fillchar(next,sizeof(next),0);
  fillchar(line,sizeof(line),0);
  fillchar(c,sizeof(c),0);

  for i:=1 to n do father[i]:=i;
  for i:=1 to m do
  begin
    fa:=e[i].x; fb:=e[i].y;
    fa:=getfather(fa); fb:=getfather(fb);
    if fa<>fb then
    begin
      add(i);
      father[fa]:=fb;
    end;
  end;
end;
function min(a,b:longint):longint;
begin
  if a<b then exit(a)
  else exit(b);
end;
procedure dfs(u,path,x:longint);
var t,pre:longint;
begin
  flag[u]:=1; ans[x,u]:=path; ans[u,x]:=path;
  t:=num[u]; pre:=line[t];
  while t<>0 do
  begin
    if flag[pre]=0 then dfs(pre,min(path,c[t]),x);
    t:=next[t]; pre:=line[t];
  end;
end;
procedure calc;
var i:longint;
begin
  fillchar(ans,sizeof(ans),$ff);
  for i:=1 to n do
  begin
    fillchar(flag,sizeof(flag),0);
    dfs(i,100001,i);
  end;
end;
procedure print;
var q,a,b:longint;
    i:longint;
begin
  readln(q);
  for i:=1 to q do
  begin
    readln(a,b);
    writeln(ans[a,b]);
  end;
end;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);
  init;
  kruscal;
  calc;
  print;
  close(input);
  close(output);
end.