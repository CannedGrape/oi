var first,next,other,value:array[1..100000] of longint;
    i,j,k,tot,x,y,z,p,n,m:longint;
    now:array[1..10000] of boolean;
    dis:array[1..10000] of longint;
    a:array[1..30000,1..2] of longint;
    d:array[1..10000000] of longint;

procedure add(x,y,z:longint);
begin
  inc(tot);
  next[tot]:=first[x];
  first[x]:=tot;
  other[tot]:=y;
  value[tot]:=z;
end;

function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;

procedure spfa(x:longint);
var i,j,k,t,h:longint;
begin
  h:=1;t:=1;
  d[h]:=x;
  fillchar(now,sizeof(now),true);
  fillchar(dis,sizeof(dis),0);
  now[x]:=false;
  dis[x]:=maxlongint;
  while h<=t do
    begin
      i:=first[d[h]];
      while i<>0 do
        begin
          if min(value[i],dis[d[h]])>dis[other[i]] then
            begin
              dis[other[i]]:=min(value[i],dis[d[h]]);
              if now[other[i]] then
                begin
                  inc(t);
                  d[t]:=other[i];
                  now[other[i]]:=false;
                end;
            end;
          i:=next[i];
        end;
      now[d[h]]:=true;
      inc(h);
    end;
end;

procedure px(l,r:longint);
var i,j,k,t,p:longint;
begin
  i:=l;j:=r;
  k:=a[(l+r)shr 1,1];
  repeat
    while a[i,1]<k do inc(i);
    while a[j,1]>k do dec(j);
    if i<=j then
      begin
        for p:=1 to 2 do
          begin
            t:=a[i,p];a[i,p]:=a[j,p];a[j,p]:=t;
          end;
        inc(i);dec(j);
      end;
  until i>j;
  if l<j then px(l,j);
  if i<r then px(i,r);
end;

BEGIN
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y,z);
      add(x,y,z);
      add(y,x,z);
    end;
  readln(p);
  for i:=1 to p do
    begin
      readln(x,y);
      if x>y then begin a[i,1]:=y;a[i,2]:=x; end else
        begin
          a[i,1]:=x;
          a[i,2]:=y;
        end;
    end;
  px(1,p); k:=0;
  for i:=1 to p do
    begin
      if a[i,1]<>k then begin spfa(a[i,1]);k:=a[i,1]; end;
     if dis[a[i,2]]<>0 then writeln(dis[a[i,2]]) else writeln(-1);
    end;
  close(input);close(output);
end.