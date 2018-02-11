const dx:array[1..4] of longint=(0,1,0,-1);
      dy:array[1..4] of longint=(1,0,-1,0);

var  n,m,q,i,s1,s2,e1,e2,k1,k2,j:longint;
     bo:array[0..35,0..35] of boolean;
     w:array[0..35,0..35,0..35,0..35] of longint;
     a,v,w1:array[0..35,0..35] of longint;
     d1,d2,wt1,wt2:array[0..500] of longint;

function min(x,y:longint):longint;
begin
    if x<y then exit(x);
    exit(y);
end;

procedure bfs(q,p:longint);
var  head,tail,i,xx,yy,x,y:longint;
begin
     head:=0; tail:=1;
     d1[1]:=q; d2[1]:=p;
     w1[q,p]:=0;
     repeat
       inc(head);
       x:=d1[head]; y:=d2[head];
       for i:=1 to 4 do
       begin
         xx:=x+dx[i]; yy:=y+dy[i];
         if (xx>0) and (yy>0) and (xx<=n) and (yy<=m) and (w[q,p,xx,yy]>w[q,p,x,y]+1) and (a[xx,yy]=1)then
         begin
           w[q,p,xx,yy]:=min(w[q,p,x,y]+1,w[q,p,xx,yy]);
           inc(tail); d1[tail]:=xx; d2[tail]:=yy;
         end;
       end;
     until head=tail;
end;


procedure bfs1(q,p:longint);
var  head,tail,i,xx,yy,x,y:longint;
begin
     head:=0; tail:=1;
     d1[1]:=q; d2[1]:=p;
     w1[q,p]:=0;
     repeat
       inc(head);
       x:=d1[head]; y:=d2[head];
       for i:=1 to 4 do
       begin
         xx:=x+dx[i]; yy:=y+dy[i];
         if (xx>0) and (yy>0) and (xx<=n) and (yy<=m) and (w1[xx,yy]>w1[x,y]+1) and (a[xx,yy]=1) and not bo[xx,yy]then
         begin
           w1[xx,yy]:=min(w1[x,y]+1,w1[xx,yy]);
           inc(tail); d1[tail]:=xx; d2[tail]:=yy;
         end;
       end;
     until head=tail;
end;

procedure find(q,p:longint);
var  head,tail,xx,yy,x,y,i:longint;
begin
     head:=0; tail:=1;
     d1[1]:=q; d2[1]:=p; wt1[1]:=k1; wt2[1]:=k2;
     v[q,p]:=0;
     repeat
      inc(head);
      x:=d1[head]; y:=d2[head];
      for i:=1 to 4 do
      begin
        xx:=x+dx[i]; yy:=y+dy[i];
        if w[wt1[head],wt2[head],xx,yy]>10000 then continue;
        if (xx>0) and (yy>0) and (xx<=n) and (yy<=n) {and (v[xx,yy]>v[x,y]+w[wt1[head],wt2[head],xx,yy]+1)}then
        begin
          fillchar(w1,sizeof(w1),$3f);
          fillchar(bo,sizeof(bo),false);
          bo[x,y]:=true;
          bfs1(wt1[head],wt2[head]);
          if v[xx,yy]>v[x,y]+w1[xx,yy]+1 then
          begin
           v[xx,yy]:=v[x,y]+w1[xx,yy]+1;
           inc(tail);
           d1[tail]:=xx; d2[tail]:=yy;
           wt1[tail]:=x; wt2[tail]:=y;
          end;
        end;
      end;
     until head=tail;
end;

begin
    assign(input,'puzzle.in'); reset(input);
    assign(output,'puzzle.out'); rewrite(output);
    readln(n,m,q);
    for i:=1 to n do
     for j:=1 to m do
     begin
      read(a[i,j]);
     end;

    fillchar(w,sizeof(w),$3f);
    fillchar(w1,sizeof(w1),$3f);
    for i:=1 to n do
     for j:=1 to m do
      if a[i,j]=1 then
      begin
       w[i,j,i,j]:=0;
       bfs(i,j);
      end;
    for i:=1 to q do
    begin
     readln(k1,k2,s1,s2,e1,e2);
     if w[s1,s2,e1,e2]>10000 then
     begin
      writeln(-1);
      continue;         \
     end;
     if (s1=e1) and (s2=e2) then
     begin
      writeln(0);
      continue;
     end;
     fillchar(v,sizeof(v),$3f);
     find(s1,s2);
     if v[e1,e2]>10000 then writeln(-1)
      else writeln(v[e1,e2]);
    end;
  {  fillchar(w1,sizeof(w1),$3f);
    fillchar(bo,sizeof(bo),false);
    bfs1(2,2);
    writeln(w1[3,2]); }
    close(input); close(output);
end.

