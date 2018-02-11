var dis:array[0..2000]of longint;
    bo:array[0..2000]of boolean;
    ans:array[0..2000]of longint;
    first,en,w,next:array[0..100001]of longint;
    n,m,i,j,k,xx,yy,zz,tot,q,head,tail,u,v:longint;
    co:array[0..2000]of boolean;
    team:array[0..100000]of longint;
    x,y:array[0..2000]of longint;
procedure setl(xx,yy,zz:longint);
begin
 inc(tot);
 next[tot]:=first[xx];
 first[xx]:=tot;
 en[tot]:=yy;
 w[tot]:=zz;
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a) else exit(b);
end;
procedure spfa(s:longint);
var i:longint;
begin
  for i:=1 to n do dis[i]:=-99999999;
  dis[s]:=200000;
  head:=0; tail:=1;
  team[1]:=s;
  repeat
   inc(head);
   u:=team[head];
   co[u]:=false;
   i:=first[u];
   while i<>0 do
    begin
     v:=en[i];
     if min(dis[u],w[i])>dis[v] then
      begin
       dis[v]:=min(dis[u],w[i]);
       if not co[v] then
        begin
         inc(tail);
         team[tail]:=v;
         bo[v]:=true;
        end;
      end;
     i:=next[i];
    end;
  until head>=tail;
end;
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
   begin
     readln(xx,yy,zz);
     setl(xx,yy,zz);
     setl(yy,xx,zz);
   end;
  readln(q);
  for i:=1 to q do
    begin
     readln(x[i],y[i]);
     bo[x[i]]:=true;
    end;
  for i:=1 to n do
   if bo[i] then
    begin
     spfa(i);
     for j:=1 to q do
      if x[j]=i then
       begin
        if (dis[y[j]]<>-99999999)and(dis[y[j]]<>200000) then ans[j]:=dis[y[j]] else
         ans[j]:=-1; //writeln(ans[j],' ',j);
       end;
    end;
  for i:=1 to q do writeln(ans[i]);
  close(input); close(output);
end.