Program mxpiii;
Var
   next,first,last,value:array[0..100030] of longint;
   vis,exi:array[0..10000] of boolean;
   f:array[0..2000] of longint;
   link:array[0..1000,0..1000] of boolean;
   qx,qy,qz,ans:array[0..30000] of longint;
   m,n,tot,q,i,x,y,z,t,head,tail:longint;
   flag:boolean;

Procedure add_edge(x,y,z:longint);
Begin
  inc(tot);
  next[tot]:=first[x];
  first[x]:=tot;
  last[tot]:=y;
  value[tot]:=z;
End;

Procedure qsort(l,r:longint);
Var
   i,j,midx,midy,p:longint;
Begin
   i:=l; j:=r; midx:=qx[(l+r) div 2]; midy:=qy[(l+r) div 2];
   repeat
     while (qx[i]<midx) or ((qx[i]=midx) and (qy[i]<midy)) do inc(i);
     while (qx[j]>midx) or ((qx[j]=midx) and (qy[j]>midy)) do dec(j);
     if i<=j then
       begin
         p:=qx[i]; qx[i]:=qx[j]; qx[j]:=p;
         p:=qy[i]; qy[i]:=qy[j]; qy[j]:=p;
         p:=qz[i]; qz[i]:=qz[j]; qz[j]:=p;
         inc(i); dec(j);
       end;
   until i>j;
   if l<j then qsort(l,j);
   if i<r then qsort(i,r);
End;

{Procedure bfs(x:longint);
Var
   i,u,v:longint;
Begin
   fillchar(exi,sizeof(exi),0);
   head:=0;tail:=1;
   f[1]:=x; exi[x]:=true;
   repeat
     inc(head);
     u:=f[head];
     i:=first[i];
     while i<>0 do
       begin
          v:=last[i];
          if not exi[v] then
            begin
              inc(tail);
              f[tail]:=v;
              link[u][v]:=true;
            end;
          i:=next[i];
       end;
   until head>=tail;
End;   }

Procedure dfs(now,des,min:longint);
Var
  i,u:longint;
Begin
   if now=des then
     begin
       flag:=true; exit;
     end;
   //if not link[now][des] then exit;
   vis[now]:=true;
   i:=first[now];
   while i<>0 do
     begin
       u:=last[i];
       if value[i]>=min then
         if not vis[u] then
           dfs(u,des,min);
       i:=next[i];
     end;
   vis[now]:=false;
End;

Function can(v,x,y:longint):boolean;
Begin
   flag:=false;
   dfs(x,y,v);
   if flag then exit(true) else exit(false);
End;

Function find(x,y:longint):longint;
Var
   l,r,mid:longint;
Begin
   find:=-1;
   l:=0; r:=100000;
   while (r-l>1) do
     begin
       mid:=(l+r) div 2;
       if can(mid,x,y) then
         begin
           if mid>find then find:=mid;
           l:=mid
         end
       else r:=mid-1;
     end;
   if l>find then if can(l,x,y) then find:=l;
   if r>find then if can(r,x,y) then find:=r;
   exit(find);
End;

Begin
   assign(input,'truck.in');
   assign(output,'truck.out');
   reset(input);
   rewrite(output);
   readln(n,m);
   fillchar(ans,sizeof(ans),$7f);
   fillchar(vis,sizeof(vis),0);
   //fillchar(link,sizeof(link),0);
   tot:=0;
   for i:=1 to m do
     begin
       readln(x,y,z);
       add_edge(x,y,z);
       add_edge(y,x,z);
     end;
   //for i:=1 to n do bfs(i);
   readln(q);
   for i:=1 to q do
     begin
       readln(qx[i],qy[i]);
       if qx[i]>qy[i] then
         begin
           t:=qx[i]; qx[i]:=qy[i]; qy[i]:=t;
         end;
       qz[i]:=i;
     end;
   qsort(1,q);
   for i:=1 to q do
     begin
       if (qx[i]=qx[i-1]) and (qy[i]=qy[i-1]) and (ans[qz[i-1]]<=100000)
       then ans[qz[i]]:=ans[qz[i-1]]
       else
         begin
           ans[qz[i]]:=find(qx[i],qy[i]);
         end;
     end;
   for i:=1 to q do writeln(ans[i]);
   close(input);
   close(output);
End.
