var n,m,x,y,z,i,j,k,tot,now,too,l,r,ii:longint;
    e:array[0..200010,0..3]of longint;
    las,fa,num,dis:array[0..10010]of longint;
    b,vis:array[0..10010]of boolean;
    q:array[0..1000000]of longint;
    ans:array[0..1010,0..1010]of longint;
//    ans:array[-1..1000000,0..3]of longint;
procedure add(x,y,z:longint);
begin
  tot:=tot+1;
  e[tot,0]:=x;
  e[tot,1]:=y;
  e[tot,2]:=z;
  e[tot,3]:=las[x];
  las[x]:=tot;
end;
function gf(x:longint):longint;
begin
  if fa[x]<>x then fa[x]:=gf(fa[x]);
  gf:=fa[x];
end;
procedure swap(var x,y:longint);
var i:longint;
begin
  if x>y then
  begin i:=x;x:=y;y:=i;end;
end;
function min(a,b:longint):longint;
begin min:=a;if a>b then min:=b;end;
{procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=ans[(l+r)shr 1,0];
  y:=ans[(l+r)shr 1,1];
  repeat
    while(ans[i,0]<x)or(ans[i,0]=x)and(ans[i,1]<y)do inc(i);
    while(x<ans[j,0])or(ans[j,0]=x)and(y<ans[j,1])do dec(j);
    if i<=j then
    begin
      ans[-1]:=ans[i];ans[i]:=ans[j];ans[j]:=ans[-1];
      inc(i);j:=j-1;
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;}
{function find(x,y:longint):longint;
var l,r,mid:longint;
begin
  l:=1;r:=ans[0,0];
  while l<r do
  begin
    mid:=(l+r)shr 1;
    if ans[mid,0]=x then
    begin
      if ans[mid,1]=y then exit(mid)
      else if ans[mid,1]<y then l:=mid+1
      else r:=mid;
    end
    else
    if ans[mid,0]<x then l:=mid+1
    else r:=mid;
  end;
  if(ans[l,0]=x)and(ans[l,1]=y)then exit(l)
  else exit(-1);
end;    }
begin
assign(input,'truck.in');
assign(output,'truck.out');
reset(input);rewrite(output);
  readln(n,m);tot:=0;
  for i:=1 to n do begin fa[i]:=i;num[i]:=1;end;
  for i:=1 to m do
  begin
    readln(x,y,z);
    add(x,y,z);
    add(y,x,z);
    j:=gf(x);k:=gf(y);
    if j<>k then
    begin
      fa[j]:=k;
      num[k]:=num[k]+num[j];
      num[j]:=0;
    end;
  end;
  readln(m);
  for ii:=1 to m do
  begin
    readln(x,y);swap(x,y);
    if gf(x)<>gf(y)then
    begin
      writeln(-1);
      continue;
    end;
 {   l:=find(x,y);}
    if ans[x,y]<>0 then
    begin
      writeln(ans[x,y]);
      continue;
    end;
    l:=1;r:=1;q[1]:=x;ans[0,1]:=ans[0,0]+1;
    fillchar(dis,sizeof(dis),0);
    fillchar(vis,sizeof(vis),false);
    dis[x]:=1000000;vis[x]:=true;
    while l<=r do
    begin
      now:=q[l];
      i:=las[now];
      while i<>0 do
      begin
        too:=e[i,1];
        if min(dis[now],e[i,2])>dis[too]then
        begin
          dis[too]:=min(dis[now],e[i,2]);
          if(too=x)or(now=x)then
          begin
{            ans[0,0]:=ans[0,0]+1;
            ans[ans[0,0],0]:=too;
            ans[ans[0,0],1]:=now;
            swap(ans[ans[0,0],0],ans[ans[0,0],1]);   }
            ans[too,now]:=dis[too];
            ans[now,too]:=dis[too];
          end;
          if vis[too]=false then
          begin
            r:=r+1;
            q[r]:=too;
          end;
        end;
        i:=e[i,3];
      end;
      l:=l+1;
    end;
    writeln(dis[y]);
{    for i:=ans[0,1]to ans[0,0]do
    ans[i,2]:=dis[ans[i,0]+ans[i,1]-x];
    sort(1,ans[0,0]);  }
{
    for i:=1 to ans[0,0]do
    writeln(ans[i,0],' ',ans[i,1],' ',ans[i,2]);
    writeln;
}
  end;
  close(input);close(output);
end.

