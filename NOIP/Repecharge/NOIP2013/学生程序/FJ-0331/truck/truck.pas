var x,y,z,star,fini,wh,ans,ji,dis:array[0..50000]of longint;
    use:array[1..50000]of boolean;
    team:array[1..200000]of longint;
    i,j,n,m,q:longint;

procedure swap(var a,b:longint);
var t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure kp(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=x[(i+r) shr 1];
  repeat
    while x[i]<m do inc(i);
    while x[j]>m do dec(j);
    if i<=j then
      begin
        swap(x[i],x[j]);
        swap(y[i],y[j]);
        swap(z[i],z[j]);
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;

procedure kp1(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=star[(i+r) shr 1];
  repeat
    while star[i]<m do inc(i);
    while star[j]>m do dec(j);
    if i<=j then
      begin
        swap(star[i],star[j]);
        swap(fini[i],fini[j]);
        swap(wh[i],wh[j]);
        swap(ans[i],ans[j]);
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then kp1(i,r);
  if l<j then kp1(l,j);
end;

function min(a,b:longint):longint;
begin
  if a>b then exit (b)
  else
  exit(a);
end;

procedure spfa(c:longint);
var t,w,i,u:longint;
begin
  for i:=1 to n do
    begin
      use[i]:=true;
      dis[i]:=-1;
    end;
  t:=0;w:=1;dis[star[c]]:=300000;
  use[star[c]]:=false;
  team[1]:=star[c];
  repeat
    inc(t);
    t:=(t-1) mod 30000+1;
    u:=team[t];use[u]:=true;
    for i:=ji[u] downto 1 do
      begin
        if x[i]<>u then
          break;
        if dis[y[i]]<min(dis[u],z[i]) then
          begin
            dis[y[i]]:=min(dis[u],z[i]);
            if use[y[i]] then
              begin
                inc(w);
                w:=(w-1) mod 30000+1;
                use[y[i]]:=false;
                team[w]:=y[i];
              end;
          end;
      end;
  until t=w;
end;

procedure kp2(l,r:longint);
var i,j,m:longint;
begin
  i:=l;j:=r;m:=wh[(i+r) shr 1];
  repeat
    while wh[i]<m do inc(i);
    while wh[j]>m do dec(j);
    if i<=j then
      begin
        swap(wh[i],wh[j]);
        swap(ans[i],ans[j]);
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then kp2(i,r);
  if l<j then kp2(l,j);
end;

begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      readln(x[i],y[i],z[i]);
      y[m+i]:=x[i];
      z[m+i]:=z[i];
      x[m+i]:=y[i];
    end;
  kp(1,2*m);
  for i:=1 to 2*m do
    ji[x[i]]:=i;
  readln(q);
  for i:=1 to q do
    begin
      readln(star[i],fini[i]);
      wh[i]:=i;
    end;
  kp1(1,q);
  i:=1;star[0]:=0;
  while i<>q+1 do
    begin
      if star[i]<>star[i-1] then
        begin
          spfa(i);
        end;
      ans[i]:=dis[fini[i]];
      inc(i);
    end;
  kp2(1,q);
  for i:=1 to q do
    if (ans[i]>0)and(ans[i]<=100000) then
      writeln(ans[i])
      else
      writeln('-1');
close(input);
  close(output);
end.
