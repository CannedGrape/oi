var map,dis:array[0..1000,0..1000]of longint;
    n,m,x,y,z,i,j,q,k,tot,p:longint;
    qa,qb,ans,dist:array[0..10000]of longint;
    v:array[0..10000]of boolean;
    fa,son,before,w:array[0..100000]of longint;
    f:array[0..5000000]of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)
  else exit(b);
end;
function min(a,b:longint):longint;
begin
  if a<b then exit(a)
  else exit(b);
end;
procedure spfa(t:longint);
var head,tail:longint;
begin
  head:=0;tail:=1;
  f[1]:=t;
  v[t]:=true;
  fillchar(v,sizeof(v),false);
  fillchar(dist,sizeof(dist),$ff);
  while head<tail do
    begin
      inc(head);
      k:=son[f[head]];
      while k<>0 do
        begin
          if dist[f[head]]=-1 then dist[f[head]]:=maxlongint;
          if (dist[fa[k]]<min(dist[f[head]],w[k])) then
            dist[fa[k]]:=min(dist[f[head]],w[k]);
          if not v[fa[k]] then
           begin
             inc(tail);
             v[fa[k]]:=true;
             f[tail]:=fa[k];
           end;
           k:=before[k];
        end;
    end;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  if n<=1000 then
    begin
      fillchar(dis,sizeof(dis),$ff);
      for i:=1 to m do
        begin
         readln(x,y,z);
         map[x,y]:=max(map[x,y],z);
         dis[x,y]:=map[x,y];
         map[y,x]:=map[x,y];
         dis[y,x]:=map[y,x];
        end;
      for k:=1 to n do
        for i:=1 to n do
          if k<>i then
            for j:=1 to n do
              if (j<>k) and (j<>i) then
                dis[i,j]:=max(dis[i,j],min(dis[i,k],dis[k,j]));
      readln(q);
      for i:=1 to q do
        begin
          readln(x,y);
          writeln(dis[x,y]);
        end;
      close(input);close(output);
      halt;
    end
  else
    begin
    tot:=0;
      for i:=1 to m do
        begin
          readln(x,y,z);
          inc(tot);
          fa[tot]:=y;before[tot]:=son[x];son[x]:=tot;w[tot]:=z;
          inc(tot);
          fa[tot]:=x;before[tot]:=son[y];son[y]:=tot;w[tot]:=z;
        end;
      readln(p);
      for i:=1 to p do
        begin
          readln(x,y);
          qa[i]:=x;
          qb[i]:=y;
        end;
        fillchar(ans,sizeof(ans),$ff);
      for i:=1 to n do
        begin
          spfa(i);
          for j:=1 to p do
          begin
            if (qa[j]=i) then
              ans[j]:=dist[qb[j]];
            if (qb[j]=i) then
              ans[j]:=dist[qa[j]];
          end;
        end;
      for i:=1 to p do
        writeln(ans[i]);
        close(input);close(output);
        halt;
    end;
end.
