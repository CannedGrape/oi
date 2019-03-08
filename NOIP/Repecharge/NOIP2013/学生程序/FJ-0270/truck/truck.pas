var n,m,i,maxz,tot,x,y,z,l,mid,r,ans:longint;
    flag:boolean;
    first,q:array[0..10010]of longint;
    vis:array[0..10010]of boolean;
    v,w,next:array[0..100010]of longint;
function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;
procedure add(x,y,z:longint);
var t:longint;
begin
  t:=first[x];
  while t>0 do
  begin
    if v[t]=y then
    begin
      w[t]:=max(w[t],z);
      exit;
    end;
    t:=next[t];
  end;
  inc(tot);v[tot]:=y;w[tot]:=z;next[tot]:=first[x];first[x]:=tot;
end;
function check(x,y,mid:longint):boolean;
var head,tail,t:longint;
begin
  for t:=1 to n do vis[t]:=false;
  head:=0;
  tail:=1;
  q[1]:=x;
  vis[x]:=true;
  while head<>tail do
  begin
    inc(head);
    t:=first[q[head]];
    while t>0 do
    begin
      if v[t]=y then flag:=true;
      if mid<=w[t] then
      begin
        if v[t]=y then
        begin
          check:=true;
          exit;
        end;
        if not vis[v[t]] then
        begin
          inc(tail);
          q[tail]:=v[t];
          vis[v[t]]:=true;
        end;
      end;
      t:=next[t];
    end;
  end;
  check:=false;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do first[i]:=0;
  maxz:=0;tot:=0;
  for i:=1 to m do
  begin
    readln(x,y,z);maxz:=max(z,maxz);
    add(x,y,z);add(y,x,z);
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(x,y);
    flag:=false;
    l:=0;r:=maxz;
    while l<=r do
    begin
      mid:=(l+r) shr 1;
      if check(x,y,mid) then
      begin
        ans:=mid;
        l:=mid+1;
      end else r:=mid-1;
    end;
    if flag then writeln(ans) else writeln(-1);
  end;
  close(input);close(output);
end.
