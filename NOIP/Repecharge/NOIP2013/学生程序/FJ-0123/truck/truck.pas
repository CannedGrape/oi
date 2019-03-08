var yx,pro,next,a,b,c,w,p,pre,v:array [0..20000] of longint;
    f:array[0..1000,0..1000] of longint;
    tot,num,n,m,q,i,j,x1,x3,x2:longint;

procedure work(p1,p2:longint);
var v1,v2,v3,v4:longint;
begin
  v1:=p1;v2:=p2;v3:=c[(p1+p2)div 2];
  repeat
    while c[v1]>v3 do inc(v1);
    while c[v2]<v3 do dec(v2);
    if v1<=v2 then
    begin
      v4:=a[v1];a[v1]:=a[v2];a[v2]:=v4;
      v4:=b[v1];b[v1]:=b[v2];b[v2]:=v4;
      v4:=c[v1];c[v1]:=c[v2];c[v2]:=v4;
      inc(v1);dec(v2);
    end
  until v1>v2;
  if v1<p2 then work(v1,p2);
  if p1<v2 then work(p1,v2);
end;
function father(p1:longint):longint;
begin
  if pre[p1]=p1 then father:=p1
  else
  begin
    pre[p1]:=father(pre[p1]);
    father:=pre[p1];
  end;
end;
procedure merge(p1,p2,p3:longint);
begin
  inc(num);
  yx[num]:=p2;
  w[num]:=p3;
  next[num]:=pro[p1];
  pro[p1]:=num;
end;
function min(p1,p2:longint):longint;
begin
  if p1<p2 then min:=p1 else min:=p2;
end;
function dfs(p1:longint):longint;
var p2,p3,p4,p6,p7:longint;
    t:boolean;
begin
  p2:=pro[p1];
  v[p1]:=1;
  t:=true;
  while p2>0 do
  begin
    p3:=yx[p2];
    if v[p3]=0 then
    begin
      if t then
      begin
        t:=false;
        p4:=dfs(p3);
        p6:=p4;
      end
      else p6:=dfs(p3);
      f[p[tot],p1]:=w[p2];
      f[p1,p[tot]]:=w[p2];
      for p7:=p6 to tot-1 do
      begin
        f[p[p7],p1]:=min(f[p[p7],p[tot]],f[p[tot],p1]);
        f[p1,p[p7]]:=f[p[p7],p1];
      end;
    end;
    p2:=next[p2];
  end;
  inc(tot);
  p[tot]:=p1;
  if t then
    dfs:=tot
    else
  begin
    for p2:=p4 to tot-2 do
      for p3:=p2+1 to tot-1 do
      if f[p[p2],p[p3]]=0 then
      begin
        f[p[p2],p[p3]]:=min(f[p[p2],p1],f[p[p3],p1]);
        f[p[p3],p[p2]]:=f[p[p2],p[p3]];
      end;
    dfs:=p4;
  end;
end;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    readln(a[i],b[i],c[i]);
  for i:=1 to n do pre[i]:=i;
  work(1,m);
  while tot<=m do
  begin
    inc(tot);
    if father(a[tot])<>father(b[tot]) then
    begin
      pre[pre[a[tot]]]:=pre[b[tot]];
      merge(a[tot],b[tot],c[tot]);
      merge(b[tot],a[tot],c[tot]);
    end;
  end;
  for i:=1 to n do
  if v[i]=0 then
    x1:=dfs(i);
  readln(q);
  for i:=1 to q do
  begin
    readln(x1,x2);
    if f[x1,x2]=0 then writeln(-1)
    else writeln(f[x1,x2]);
  end;
  close(input);
  close(output);
end.

