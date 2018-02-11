type rec=record
     next,f,t,v:longint;
     end;
var d:array [0..100001] of rec;
    a,b,c:array [0..100001] of longint;
    front:array [0..10001] of longint;
    ans:array [0..30001] of longint;
    asklink,askx,asky:array [0..30001] of longint;
    dist:array [0..10001] of longint;
    que:array [0..10001] of longint;
    f:array [0..10001] of boolean;
    n,m,i,len,x,y,z,q:longint;
procedure add(x,y,z:longint);
begin
  inc(len);
  d[len].next:=front[x];
  front[x]:=len;
  d[len].f:=x;
  d[len].t:=y;
  d[len].v:=z;
end;
procedure swap(var a,b:longint);
var t:longint; begin t:=a; a:=b; b:=t; end;
procedure sort(l,r:longint);
var i,j:longint;
    x,y:longint;
begin
  i:=l;
  j:=r;
  x:=askx[(((l+r) div 2)+r) div 2];
  repeat
    while askx[i]<x do inc(i);
    while x<askx[j] do dec(j);
    if not(i>j)
    then
      begin
        y:=askx[i]; askx[i]:=askx[j]; askx[j]:=y;
        y:=asky[i]; asky[i]:=asky[j]; asky[j]:=y;
        y:=asklink[i]; asklink[i]:=asklink[j];
        asklink[j]:=y; inc(i); dec(j);
      end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
procedure sort1(l,r:longint);
var i,j,x,y,x1,x2:longint;
begin
  i:=l;
  j:=r;
  x:=a[(((l+r) div 2)+r) div 2];
  x1:=b[(((l+r) div 2)+r) div 2];
  x2:=c[(((l+r) div 2)+r) div 2];
  repeat
    while (a[i]<x) or
           ((a[i]=x) and (b[i]<x1)) or
           ((a[i]=x) and (b[i]=x1) and (c[i]>x2))
      do inc(i);
    while (x<a[j]) or
           ((a[j]=x) and (b[j]>x1)) or
           ((a[j]=x) and (b[j]=x1) and (c[j]<x2))
      do dec(j);
    if not(i>j)
    then
      begin
        y:=a[i]; a[i]:=a[j]; a[j]:=y;
        y:=b[i]; b[i]:=b[j]; b[j]:=y;
        y:=c[i]; c[i]:=c[j]; c[j]:=y;
        inc(i);
        j:=j-1;
      end;
  until i>j;
  if l<j then sort1(l,j);
  if i<r then sort1(i,r);
end;
function min(a,b:longint):longint;
begin if a<b then exit(a) else exit(b); end;
function max(a,b:longint):longint;
begin if a>b then exit(a) else exit(b); end;
procedure spfa(st:longint);
var i,l,r,l1,r1,point,t:longint;
begin
  l:=0; r:=1;
  l1:=0; r1:=1;
  que[0]:=st;
  for i:=1 to n do
    begin
      dist[i]:=-1;
      f[i]:=true;
    end;
  f[st]:=false;
  dist[st]:=maxlongint;
  while l1<r1 do
    begin
      point:=front[que[l]];
      while point<>-1 do
        begin
          t:=d[point].t;
          if dist[t]<min(dist[que[l]],d[point].v)
          then
            begin
              dist[t]:=min(dist[que[l]],d[point].v);
              if f[t]
              then
                begin
                  que[r]:=t;
                  f[t]:=false;
                  inc(r);
                  inc(r1);
                  r:=r mod 10000;
                end;
            end;
          point:=d[point].next;
        end;
      f[que[l]]:=true;
      inc(l1);
      inc(l);
      l:=l mod 10000;
    end;
end;
begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);
rewrite(output);

  readln(n,m);
  len:=0;
  fillchar(front,sizeof(front),$FF);
  for i:=1 to m do
    begin
      readln(a[i],b[i],c[i]);
      if a[i]>b[i] then swap(a[i],b[i]);
    end;
  sort1(1,m);
  i:=1;
  while i<=m do
    begin
      add(a[i],b[i],c[i]);
      add(b[i],a[i],c[i]);
      inc(i);
      while (i<=m) and (a[i]=a[i-1]) and (b[i]=b[i-1]) do inc(i);
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(askx[i],asky[i]);
      asklink[i]:=i;
      if askx[i]>asky[i] then swap(askx[i],asky[i]);
    end;
  sort(1,q);
  i:=1;
  while i<=q do
    begin
      spfa(askx[i]);
      if dist[asky[i]]=-1
      then ans[asklink[i]]:=-1
      else ans[asklink[i]]:=dist[asky[i]];
      inc(i);
      while (i<=q) and (askx[i]=askx[i-1]) do
        begin
          if dist[asky[i]]=-1
          then ans[asklink[i]]:=-1
          else ans[asklink[i]]:=dist[asky[i]];
          inc(i);
        end;
    end;
  for i:=1 to q do writeln(ans[i]);

close(input);
close(output);
end.
