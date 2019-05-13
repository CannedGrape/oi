program core;
var depth,f,list,dist,l,dep,fa,sn:array[1..10000] of longint;
    sl,leng:array[1..10000,1..300] of longint;
    vis:array[1..10000] of boolean;
   now,x,y,t,min,w,s,n,e,ee,i,star,a,b,c:longint;
procedure dfs(u,w:longint);
var i:longint;
begin
  vis[u]:=true;
  inc(e);
  list[e]:=u;
  dep[e]:=w;
  for i:=1 to sn[u] do 
    if not vis[sl[u][i]] then begin
      fa[sl[u][i]]:=u;
      dfs(sl[u][i],w+leng[u][i]);
    end;
end;
procedure get(st:longint; var ed,len:longint);
var i:longint;
begin
  vis[st]:=true;
  dep[st]:=0;
  fa[st]:=0;
  e:=1; list[e]:=st; dep[e]:=0;
  for i:=1 to sn[st] do 
    if not vis[sl[st][i]] then begin
       fa[sl[st][i]]:=st;
       dfs(sl[st][i],leng[st][i]);
    end;
  len:=0;
  for i:=1 to e do begin
     if dep[i]>len then begin
       len:=dep[i];
       ed:=list[i];
     end;
     depth[list[i]]:=dep[i];
  end;
end;
begin
  assign(input,'core.in'); reset(input);
  assign(output,'core.out'); rewrite(output);
  readln(n,s);
  fillchar(sn,sizeof(sn),0);
  for i:=1 to n-1 do begin
    readln(a,b,c);
    inc(sn[a]);
    sl[a][sn[a]]:=b;
    leng[a][sn[a]]:=c;
    inc(sn[b]);
    sl[b][sn[b]]:=a;
    leng[b][sn[b]]:=c;
  end;
  star:=1;
  while sn[star]<>1 do inc(star);
  fillchar(vis,sizeof(vis),false);  
  get(star,b,w);  
  fillchar(vis,sizeof(vis),false);  
  get(b,a,w);
  ee:=0;
  while a<>0 do begin
    inc(ee);
    l[ee]:=a;
    dist[l[ee]]:=w-depth[a];    
    a:=fa[a];
  end;
  fillchar(vis,sizeof(vis),false);
  for i:=1 to ee do 
    vis[l[i]]:=true;
  for i:=1 to ee do 
    get(l[i],c,f[i]);
  y:=1; now:=f[1]; 
  min:=maxlongint;
  for x:=1 to ee do begin
    while y<ee do begin
      if (dist[l[y+1]]-dist[l[x]]<=s) then begin
        inc(y);
        if now<f[y] then now:=f[y];
      end
      else break;
    end;
    if dist[l[x]]>dist[l[ee]]-dist[l[y]] then t:=dist[l[x]] else t:=dist[l[ee]]-dist[l[y]];
    if now>t then begin if min>now then min:=now; end
             else begin if min>t then   min:=t;   end;
  end;
  writeln(min);
 end.
