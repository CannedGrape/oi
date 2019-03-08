program xxx;
var h,now:array [1..10000] of longint;
 f,way:array [1..10000] of longint;
 d,dis:array [1..10000] of longint;
 ne:array [1..10000] of longint;
 b:array [1..10000] of longint;
 army:array [1..10000] of longint;
 maxn,i,j,k,n,m,x,y,w,tot:longint;
procedure make(x,y,w:longint);
begin
   inc(tot); dis[tot]:=w;
   way[tot]:=y; ne[tot]:=0;
   if h[x]=0 then
    begin
     h[x]:=tot;
     now[x]:=tot;
    end
   else
    begin
     ne[now[x]]:=tot;
     now[x]:=tot;
    end;
end;
{function dfs(x,y:longint):longint;
begin
   if army[x]=0 then
    exit
   else
    begin
     now[x]:=h[x];
     while not(now[x]=0) do
      begin
       if f[x]<>way[now[x]] then
        begin
         f[way[now[x]]]:=x;
         for j:=-1 to army[x] do
          for i:=0 to army[way[now[x]]] do
           dp[x,j+i]:=min(dp[x,j+i],
           max(dfs(way[now[x]],i)+d[way[now[x]]],dp[x,j]));
        end;
       now[i]:=ne[now[i]];
      end;
    end;
end;       }
begin
 assign(input,'blockade.in');
 assign(output,'blockade.out');
 reset(input); rewrite(output);
 read(n);
 for i:=1 to n-1 do
  begin
   read(x,y,w);
   make(x,y,w);
   make(y,x,w);
  end;
{ ii:=0; j:=1; b[1]:=1;
 while ii<j do
  begin
   inc(ii); i:=b[ii]; now[i]:=h[i];
   while not(now[i]=0) do
    begin
     if f[i]<>way[now[i]] then
      begin
       f[way[now[i]]]:=i;
       d[way[now[i]]]:=dis[now[i]];
       inc(j); b[j]:=way[now[i]];
      end;
     now[i]:=ne[now[i]];
    end;
  end;}
 read(m);
 for i:=1 to m do
  begin read(x,y); army[y]:=x; maxn:=maxn+x; end;
 for i:= n downto 1 do army[f[i]]:=army[f[i]]+army[i];
{ while not now[1]=0 do
  begin
   for i:=0 to army[way[now[1]] do
    dfs(way[now[1]]);
   now[i]:=ne[now[i]];
  end;}
 writeln(-1);
 close(input); close(output);
end.