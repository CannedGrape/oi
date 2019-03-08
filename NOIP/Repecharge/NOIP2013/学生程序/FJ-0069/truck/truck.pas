program p3;
var n,m,i,j,x,y,z,qq,tot:longint;
    head:array[0..10010]of longint;
    next,v,num:array[0..100010]of longint;
    f:array[0..1000,0..1000]of longint;
    vis:array[0..10010]of boolean;
    q:array[0..1000000]of longint;
function min(a,b:longint):longint;
begin
  if a<b then exit(a);
  exit(b);
end;
function max(a,b:longint):longint;
begin
  if a>b then exit(a);
  exit(b);
end;
procedure add(x,y,z:longint);
begin
  inc(tot);v[tot]:=y;num[tot]:=z;
  next[tot]:=head[x];head[x]:=tot;
end;
procedure init;
var i,h,t,k:longint;
begin
  for i:=1 to n do
  begin
    h:=0;t:=1;q[1]:=i;vis[i]:=true;
    while h<t do
    begin
      inc(h);
      k:=head[q[h]];
      while k>0 do
      begin
        if f[i,v[k]]<min(f[i,q[h]],max(num[k],f[q[h],v[k]])) then
        begin
          f[i,v[k]]:=min(f[i,q[h]],max(num[k],f[q[h],v[k]]));
          if not vis[v[k]] then
          begin
            vis[v[k]]:=true;
            inc(t);
            q[t]:=v[k];
          end;
        end;
        k:=next[k];
      end;
      vis[q[h]]:=false;
    end;
  end;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do f[i,i]:=1000000;
  for i:=1 to m do
  begin
    read(x,y,z);
    add(x,y,z);
    add(y,x,z);
  end;
  init;
  readln(qq);
  for i:=1 to qq do
  begin
    read(x,y);
    if f[x,y]>0 then writeln(f[x,y])
    else writeln('-1');
  end;
  close(input);close(output);
end.