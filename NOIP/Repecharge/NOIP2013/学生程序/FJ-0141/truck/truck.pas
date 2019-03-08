function min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;
var f,dis:array[0..10001] of longint;
    ne,e,v,dui:array[0..100000] of longint;
    bo:array[0..10001] of boolean;
    ff:array[0..1500,0..1500] of longint;
    x,y,z,n,m,i,j,tou,wei,k,l,s,t,q:longint;
procedure set1(x,y,z:longint);
begin
  inc(t);
  ne[t]:=f[x];
  f[x]:=t;
  e[t]:=y;
  v[t]:=z;
  inc(t);
  ne[t]:=f[y];
  f[y]:=t;
  e[t]:=x;
  v[t]:=z;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    set1(x,y,z);
  end;
  for i:=1 to n do
  begin
    fillchar(dis,sizeof(dis),255);
    fillchar(bo,sizeof(bo),0);
    tou:=0;wei:=1;dui[1]:=i;dis[i]:=1000000000;
    while tou<wei do
    begin
      inc(tou);
      x:=dui[tou];
      bo[x]:=false;
      k:=f[x];l:=e[k];s:=v[k];
      while k<>0 do
      begin
        if min(s,dis[x])>dis[l] then
        begin
          dis[l]:=min(s,dis[x]);
          if not(bo[l]) then
          begin
            inc(wei);
            dui[wei]:=l;
          end;
        end;
        k:=ne[k];l:=e[k];s:=v[k];
      end;
    end;
    for j:=1 to n do ff[i,j]:=dis[j];
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    writeln(ff[x,y]);
  end;
  close(input);
  close(output);
end.
