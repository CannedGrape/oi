var n,m,i,j,k,q,u,v,tx,ty,tot,l,r:longint;
    f,x,y,z,ans,qx,qy,en,next,point,w,h,deep:array[0..510000]of longint;
    lca,min:array[0..11000,0..15]of longint;
    mark:array[0..11000]of boolean;
procedure add(x,y,z:longint);
begin
  inc(tot);
  next[tot]:=en[x];
  en[x]:=tot;
  point[tot]:=y;
  w[tot]:=z;
end;
function gf(x:longint):longint;
begin
  if f[x]=x then exit(x);
  f[x]:=gf(f[x]);
  exit(f[x]);
end;
procedure qs(l,r:longint);
var tl,tr,mid,tmp:longint;
begin
  tl:=l;  tr:=r;  mid:=z[(l+r) shr 1];
  repeat
    while z[tl]>mid do inc(tl);
    while z[tr]<mid do dec(tr);
    if tl<=tr then
      begin
        tmp:=y[tl];  y[tl]:=y[tr];  y[tr]:=tmp;
        tmp:=x[tl];  x[tl]:=x[tr];  x[tr]:=tmp;
        tmp:=z[tl];  z[tl]:=z[tr];  z[tr]:=tmp;
        inc(tl);  dec(tr);
      end;
  until tl>tr;
  if tl<r then qs(tl,r);
  if l<tr then qs(l,tr);
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
function fmin(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;
function lowbit(x:longint):longint;
begin
  exit(x and (-x));
end;
function ask(x,y:longint):longint;
var i,tmp:longint;
begin
  ask:=maxlongint;
  if lca[x,15]<>lca[y,15] then exit(-1);
  if deep[x]<deep[y] then
    begin
      tmp:=x;  x:=y;  y:=tmp;
    end;
  tmp:=deep[x]-deep[y];
  while tmp<>0 do
    begin
      ask:=fmin(ask,min[x,trunc(ln(lowbit(tmp))/ln(2)+1e-2)]);
      x:=lca[x,trunc(ln(lowbit(tmp))/ln(2)+1e-2)];
      tmp:=tmp-lowbit(tmp);
    end;
  while x<>y do
    begin
      for i:=1 to 15 do
        if lca[x,i]=lca[y,i] then
          begin
            ask:=fmin(ask,min[x,i-1]);
            ask:=fmin(ask,min[y,i-1]);
            x:=lca[x,i-1];  y:=lca[y,i-1];
            break;
          end;
    end;
end;
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do f[i]:=i;
  for i:=1 to m do read(x[i],y[i],z[i]);
  qs(1,m);
  readln(q);
  for i:=1 to q do read(qx[i],qy[i]);
  for i:=1 to q do ans[i]:=-1;
  for i:=1 to m do
    begin
      u:=gf(x[i]);  v:=gf(y[i]);
      if u<>v then
        begin
          add(x[i],y[i],z[i]);
          add(y[i],x[i],z[i]);
          f[u]:=v;
        end;
    end;
  h[1]:=1;  l:=0;  r:=1;  mark[1]:=true; lca[1,0]:=1; min[1,0]:=maxlongint;
  while l<r do
    begin
      inc(l);
      i:=en[h[l]];
      while i<>0 do
        if mark[point[i]]=false then
          begin
            lca[point[i],0]:=h[l];
            min[point[i],0]:=w[i];
            deep[point[i]]:=deep[h[l]]+1;
            inc(r);
            h[r]:=point[i];
            mark[h[r]]:=true;
            i:=next[i];
          end else i:=next[i];
    end;
  for i:=1 to 15 do
    for j:=1 to n do
      begin
        lca[j,i]:=lca[lca[j,i-1],i-1];
        min[j,i]:=fmin(min[j,i-1],min[lca[j,i-1],i-1]);
      end;
  for i:=1 to q do
    writeln(ask(qx[i],qy[i]));
close(input);close(output);
end.

