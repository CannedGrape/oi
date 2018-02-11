var limit:array[0..1010,0..1010] of longint;
i,j,n,m,k,l,p,tot,q:longint;
g,go:array[0..1100] of longint;
team:array[0..110000] of longint;
next,v,limitm:array[0..60000] of longint;

function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;

procedure add(j,k,l:longint);
begin
  inc(tot);
  next[tot]:=g[j];
  v[tot]:=k;
  limitm[tot]:=l;
  g[j]:=tot;
end;

procedure spfa(now:longint);
var h,t,j,i:longint;
begin
  h:=0; t:=1;
  team[1]:=now;
  while h<t do
  begin
    inc(h);
    i:=team[h];
    j:=g[i];
    while j<>0 do
    begin
      if min(go[i],limitm[j])>go[v[j]] then
      begin
        inc(t);
        team[t]:=v[j];
        go[v[j]]:=min(go[i],limitm[j]);
      end;
      j:=next[j];
    end;
  end;
end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  fillchar(limit,sizeof(limit),255);
  tot:=0;
  for i:=1 to m do
  begin
    readln(j,k,l);
    add(j,k,l);
    add(k,j,l);
  end;

  for i:=1 to n do
  begin
    for j:=1 to n do
    go[j]:=-1;
    go[i]:=maxlongint;
    spfa(i);
    for j:=1 to n do
    limit[i,j]:=go[j];
  end;

  readln(q);
  for i:=1 to q do
  begin
    readln(j,k);
    writeln(limit[j,k]);
  end;
  close(input); close(output);
end.
