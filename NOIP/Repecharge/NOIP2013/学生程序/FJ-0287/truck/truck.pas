uses math;

var i,j,m,n,o,p,q:dword;
    t:longint;
    left,right,dis:array[0..10000]of longint;
    x,y,z:array[0..100000]of dword;
    u,v,num:array[0..30000]of dword;
    team:array[0..1000000]of dword;
    ans:array[0..30000]of longint;
    ck:array[0..10000]of boolean;

function maxx(a,b:dword):dword;

begin
  if x[a]>x[b]then exit(a)else exit(b);
end;

function midx(a,b,c:dword):dword;

begin
  exit(maxx(a,b)xor maxx(a,c)xor maxx(b,c));
end;

function mid(a,b,c:dword):dword;

begin
  exit(max(a,b)xor max(a,c)xor max(b,c));
end;

procedure sort(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  o:=midx(l,(i+j)>>1,r);
  p:=x[o];
  q:=y[o];
  repeat
    while(x[i]<p)or(x[i]=p)and(y[i]<q)do inc(i);
    while(x[j]>p)or(x[j]=p)and(y[j]>q)do dec(j);
    if i<=j then
    begin
      o:=x[i];
      x[i]:=x[j];
      x[j]:=o;
      o:=y[i];
      y[i]:=y[j];
      y[j]:=o;
      o:=z[i];
      z[i]:=z[j];
      z[j]:=o;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure sortx(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  o:=midx(l,(i+j)>>1,r);
  p:=x[o];
  q:=z[o];
  repeat
    while(x[i]<p)or(x[i]=p)and(z[i]>q)do inc(i);
    while(x[j]>p)or(x[j]=p)and(z[j]<q)do dec(j);
    if i<=j then
    begin
      o:=x[i];
      x[i]:=x[j];
      x[j]:=o;
      o:=y[i];
      y[i]:=y[j];
      y[j]:=o;
      o:=z[i];
      z[i]:=z[j];
      z[j]:=o;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sortx(l,j);
  if i<r then sortx(i,r);
end;

procedure sortu(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  p:=mid(u[l],u[(i+j)>>1],u[r]);
  repeat
    while u[i]<p do inc(i);
    while u[j]>p do dec(j);
    if i<=j then
    begin
      q:=u[i];
      u[i]:=u[j];
      u[j]:=q;
      q:=v[i];
      v[i]:=v[j];
      v[j]:=q;
      q:=num[i];
      num[i]:=num[j];
      num[j]:=q;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sortu(l,j);
  if i<r then sortu(i,r);
end;

procedure last(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  p:=mid(num[l],num[(i+j)>>1],num[r]);
  repeat
    while num[i]<p do inc(i);
    while num[j]>p do dec(j);
    if i<=j then
    begin
      q:=num[i];
      num[i]:=num[j];
      num[j]:=q;
      t:=ans[i];
      ans[i]:=ans[j];
      ans[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then last(l,j);
  if i<r then last(i,r);
end;

begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  rewrite(output);
  fillchar(ck,sizeof(ck),1);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x[i],y[i],z[i]);
    x[m+i]:=y[i];
    y[m+i]:=x[i];
    z[m+i]:=z[i];
  end;
  m:=m<<1;
  sort(1,m);
  o:=1;
  for i:=2 to m do
    if(x[i]=x[o])and(y[i]=y[o])then
      if z[i]>z[o]then
      begin
        x[o]:=maxlongint;
        o:=i;
      end else x[i]:=maxlongint else o:=i;
  sortx(1,m);
  while x[m]=maxlongint do dec(m);
  left[x[1]]:=1;
  right[x[m]]:=m;
  for i:=2 to m do
    if x[i-1]<x[i]then
    begin
      right[x[i-1]]:=i-1;
      left[x[i]]:=i;
    end;
  readln(m);
  for i:=1 to m do
  begin
    readln(u[i],v[i]);
    if u[i]>v[i]then
    begin
      o:=u[i];
      u[i]:=v[i];
      v[i]:=o;
    end;
    num[i]:=i;
  end;
  sortu(1,m);
  o:=0;
  for i:=1 to m do
  begin
    if u[i]>o then
    begin
      fillchar(dis,sizeof(dis),255);
      dis[u[i]]:=maxlongint;
      team[1]:=u[i];
      p:=1;
      q:=1;
      repeat
        for j:=left[team[p]]to right[team[p]]do
          if dis[y[j]]<min(dis[team[p]],z[j])then
          begin
            dis[y[j]]:=min(dis[team[p]],z[j]);
            if ck[y[j]]then
            begin
              ck[y[j]]:=false;
              inc(q);
              team[q]:=y[j];
            end;
          end;
        ck[team[p]]:=true;
        inc(p);
      until p>q;
      o:=u[i];
    end;
    ans[i]:=dis[v[i]];
  end;
  last(1,m);
  for i:=1 to m do writeln(ans[i]);
  close(input);
  close(output);
end.