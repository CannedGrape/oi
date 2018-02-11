program truck;
type
  point=^node;
  node=record
  e,w:longint;
  next:point;
  end;
var
  n,m,q,i,j,k,x,y,z,l,r,maxx,mid:longint;
  gra:array[0..10000]of point;
  qu:array[0..50000]of integer;
  dist:array[0..10000]of longint;
  g:array[0..10000,0..10000]of ^longint;
  isok:array[0..10000]of boolean;
  p:point;
  ok,ok1:boolean;
function inse(a1:longint;p1:point):boolean;
var
  t1,t2:point;
begin
  if gra[a1]=nil then gra[a1]:=p1
  else
  begin
    t1:=gra[a1];
    while t1<>nil do
    begin
      t2:=t1;
      if t1^.e=p1^.e then
      begin
        if t1^.w<p1^.w then
        t1^.w:=p1^.w;
        exit(false);
      end;
      t1:=t1^.next;
    end;
    t2^.next:=p1;exit(true);
  end;
end;
function min(a,b:longint):longint;
begin
  if a>b then exit(b)
  else exit(b);
end;
procedure spfa(a,b:longint);
var
  t1,t2:point;
  f,r,now,ii:longint;
  iok:array[1..10000]of boolean;
begin
  for ii:=1 to n do
  begin
   iok[ii]:=false;
   dist[ii]:=-1;
  end;
  f:=0;r:=1;qu[r]:=a;iok[a]:=true;
  repeat
    inc(f);now:=qu[f];
    t1:=gra[now];
    while t1<>nil do
    begin
      if dist[t1^.e]=-1 then
      begin
        dist[t1^.e]:=min(dist[now],t1^.w);
        if not iok[t1^.e] then
        begin
          iok[t1^.e]:=true;
          inc(r);qu[r]:=t1^.e;
        end;
      end
      else if (dist[t1^.e]<t1^.w)and(t1^.w<=dist[now])then
      begin
        dist[t1^.e]:=t1^.w;
        if not iok[t1^.e] then
        begin
          iok[t1^.e]:=true;
          inc(r);qu[r]:=t1^.e;
        end;
      end
      else if (dist[t1^.e]<dist[now])and(dist[now]<=t1^.w)then
      begin
        dist[t1^.e]:=dist[now];
        if not iok[t1^.e] then
        begin
          iok[t1^.e]:=true;
          inc(r);qu[r]:=t1^.e;
        end;
      end;
      t1:=t1^.next;
    end;
    iok[now]:=false;
  until(f=r);
end;
begin
  assign(input,'truck.in');
  reset(input);
  read(n,m);
  for i:=1 to n do
  gra[i]:=nil;
  for i:=1 to m do
  begin
    read(x,y,z);if z>maxx then maxx:=z;
    new(p);p^.e:=y;p^.w:=z;p^.next:=nil;
    if not inse(x,p) then dispose(p);
    new(p);p^.e:=x;p^.w:=z;P^.next:=nil;
    if not inse(y,p) then dispose(p);
  end;
  read(q);
  assign(output,'truck.out');
  rewrite(output);
  for i:=1 to n do
  isok[i]:=false;
  for i:=1 to q do
  begin
    ok:=false;
    read(x,y);
    if not isok[x] then
    begin
     spfa(x,y);
     isok[x]:=true;
     for j:=1 to n do
     begin
       new(g[x,j]);
       g[x,j]^:=dist[j];

     end;
    end;
    writeln(g[x,y]^);
  end;
  close(input);close(output);
end.
