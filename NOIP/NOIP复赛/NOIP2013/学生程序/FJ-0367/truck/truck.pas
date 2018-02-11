var
  max,now,m,n,x,y,z,q,i:longint;
  road:array[0..10000,0..10000]of longint;
  city:array[0..10000]of boolean;
  be,en:array[0..30000]of longint;
procedure dfs(a,b:longint);
var i,t:longint;
begin
  if a=b then
  begin
    if now>max then max:=now;
    exit;
  end;
  for i:=1 to n do
  if (road[a,i]>0)and(city[i]=false) then
  begin
    t:=now;
    if now>road[a,i] then now:=road[a,i];
    city[i]:=true;
    dfs(i,b);
    now:=t;
    city[i]:=false;
  end;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    road[x,y]:=z;
    road[y,x]:=z;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    be[i]:=x; en[i]:=y;
  end;
  for i:=1 to q do
  begin
    max:=-1; now:=maxlongint;
    dfs(be[i],en[i]);
    writeln(max);
  end;
  close(input);
  close(output);
end.
