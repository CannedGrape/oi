var n,m,tot,i,p,a,b,c:longint;
    first,last,g,minn:array[1..10000]of longint;
    bo:array[1..10000]of boolean;
    bian:array[1..10000]of record
                           tou,wei,son,cost:longint;
                           end;
function min(x,y:longint):longint;
  begin
    if x>y then exit(y) else exit(x);
  end;
procedure add(x,y,z:longint);
  begin
    inc(tot);
    bian[tot].tou:=x;
    bian[tot].wei:=y;
    bian[tot].cost:=z;
    if first[x]=0 then first[x]:=tot
    else bian[first[x]].son:=tot;
    last[x]:=tot;
  end;
procedure spfa(x,y:longint);
  var top,bot,w,now,u:longint;
  begin
    fillchar(minn,sizeof(minn),0);
    fillchar(g,sizeof(g),0);
    top:=0;bot:=1;
    g[1]:=x;
    fillchar(bo,sizeof(bo),0);
    bo[x]:=true;
    minn[x]:=maxlongint;
    repeat
      inc(top);
      if top>10000 then top:=1;
      now:=g[top];
      w:=first[now];
      while w>0 do
        begin
          u:=bian[w].wei;
          if (minn[u]<min(minn[now],bian[w].cost))then
            begin
              minn[u]:=min(minn[now],bian[w].cost);
              if bo[u]=false then
                begin
                  inc(bot);
                  if bot>10000 then bot:=1;
                  g[bot]:=u;
                  bo[u]:=true;
                end;
            end;
          w:=bian[w].son;
        end;
      bo[now]:=false;
    until top=bot;
    if minn[y]=0 then writeln(-1)
    else writeln(minn[y]);
  end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  tot:=0;
  for i:=1 to m do
    begin
      readln(a,b,c);
      add(a,b,c);
      add(b,a,c);
    end;
  readln(p);
  for i:=1 to p do
    begin
      readln(a,b);
      spfa(a,b);
    end;
  close(input);close(output);
end.
