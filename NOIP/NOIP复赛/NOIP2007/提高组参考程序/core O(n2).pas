program core;
var anc,f,list,sn,dep,fa:array[1..10000] of longint;
    vis:array[1..10000] of boolean;
    map,lca,sl,leng:array[1..5000,1..5000] of longint;
    s,max,e,n,star,y,min,i,j,a,b,c,w:longint;
function getfa(a:longint):longint;
begin
  if fa[a]<>a then fa[a]:=getfa(fa[a]);
  getfa:=fa[a];
end;
procedure union(a,b:longint);
begin
  fa[getfa(a)]:=getfa(b);
end;
procedure calca(u,de:longint);
var i:longint;
begin
  fa[u]:=u;
  anc[u]:=u;
  dep[u]:=de;
  vis[u]:=true;  
  for i:=1 to sn[u] do if not vis[sl[u][i]] then 
  begin
    calca(sl[u][i],de+leng[u][i]);
    union(u,sl[u][i]);
    anc[getfa(u)]:=u;
      end;
  for i:=1 to n do if (lca[u][i] = 0)and(vis[i]) then begin
    lca[u][i]:=anc[getfa(i)];
    lca[i][u]:=lca[u][i];
  end;
end;
function getmax(u:longint):longint;
var t,i:longint;
begin
  vis[u]:=true;
  for i:=1 to sn[u] do 
    if not vis[sl[u][i]] then begin
      t:=getmax(sl[u][i])+leng[u][i];
      if t>f[u] then f[u]:=t;
    end;
  getmax:=f[u];
end;
begin
  assign(input,'core.in'); reset(input);
  assign(output,'core.out'); rewrite(output);
  readln(n,s);
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
  fillchar(fa,sizeof(fa),0);
  fillchar(vis,sizeof(vis),false);
  fillchar(dep,sizeof(dep),0);
  fillchar(lca,sizeof(lca),0);
  calca(star,0);
  max:=0;
  for i:=1 to n do 
    for j:=1 to n do begin
       map[i][j]:=dep[i]+dep[j]-(dep[lca[i][j]] shl 1);
       if map[i][j]>max then begin
         max:=map[i][j];
         a:=i; b:=j;
       end;
    end;
  e:=0; 
  fillchar(vis,sizeof(vis),false);
  repeat
    inc(e);
    vis[a]:=true;
    list[e]:=a;
    for i:=1 to n do
      if leng[a][i]+map[sl[a][i]][b]=map[a][b] then begin
        a:=sl[a][i];
        break;
      end;
  until a=b;
  if list[e]<>b then begin
    inc(e); list[e]:=b;
    vis[b]:=true;
  end;
  fillchar(f,sizeof(f),0);
  for i:=1 to e do 
    c:=getmax(list[i]);
  min:=maxlongint;
  for a:=1 to e do begin
    w:=map[list[1]][list[a]];
    for b:=a to e do begin
      if map[list[a]][list[b]]>s then break;
      if f[list[b]]>w then w:=f[list[b]];
      y:=map[list[e]][list[b]];      
      if w>y then begin if w<min then min:=w; end
             else begin if y<min then min:=y; end;
    end;
  end;
  writeln(min);
  close(input); close(output);  
end.
