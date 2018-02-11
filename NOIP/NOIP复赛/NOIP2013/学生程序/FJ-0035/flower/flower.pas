var h,num,dh:array[0..110000]of longint;
    f:array[0..110000,0..1]of longint;
    tree:array[0..410000,0..1]of longint;
    i,j,k,ans,n,maxh,tmp:longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a) else exit(b);
end;
procedure insert(l,r,x,y,z,num:longint);
var mid:longint;
begin
  if l=r then tree[num,z]:=y else
  if l>r then exit else
  begin
    mid:=(l+r) shr 1;
    if x<=mid then insert(l,mid,x,y,z,num*2) else insert(mid+1,r,x,y,z,num*2+1);
    tree[num,z]:=max(tree[num*2,z],tree[num*2+1,z]);
  end;
end;
function ask(l,r,x,y,z,num:longint):longint;
var mid:longint;
begin
  if (r<x)or(l>y) then exit(0);
  if l>r then exit(0);
  if (x<=l)and(r<=y) then exit(tree[num,z]);
  mid:=(l+r) shr 1;
  ask:=max(ask(l,mid,x,y,z,num*2),ask(mid+1,r,x,y,z,num*2+1));
end;
function make:longint;
var i,j,k:longint;
begin
  make:=0;
  for i:=1 to n do begin f[i,0]:=1;  f[i,1]:=1;  end;
  fillchar(tree,sizeof(tree),0);
  insert(1,maxh,h[1],1,1,1);
  insert(1,maxh,h[1],1,0,1);
  for i:=2 to n do
    begin
      f[i,0]:=ask(1,maxh,h[i]+1,maxh,1,1)+1;
      insert(1,maxh,h[i],f[i,0],0,1);
      f[i,1]:=ask(1,maxh,0,h[i]-1,0,1)+1;
      insert(1,maxh,h[i],f[i,1],1,1);
      make:=max(make,f[i,0]);
      make:=max(make,f[i,1]);
    end;
end;
procedure qs(l,r:longint);
var tl,tr,mid,tmp:longint;
begin
  tl:=l;  tr:=r;  mid:=h[(l+r) shr 1];
  repeat
    while h[tl]<mid do inc(tl);
    while h[tr]>mid do dec(tr);
    if tl<=tr then
      begin
        tmp:=h[tl];  h[tl]:=h[tr];  h[tr]:=tmp;
        tmp:=num[tl];  num[tl]:=num[tr];  num[tr]:=tmp;
        inc(tl);dec(tr);
      end;
  until tl>tr;
  if tl<r then qs(tl,r);
  if l<tr then qs(l,tr);
end;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  for i:=1 to n do num[i]:=i;
  qs(1,n);
  tmp:=1;
  for i:=1 to n do
    begin
      if h[i]<>h[i-1] then inc(tmp);
      dh[num[i]]:=tmp;
    end;
  h:=dh;
  for i:=1 to n do maxh:=max(maxh,h[i]);
  ans:=max(1,make);
  for i:=1 to n do h[i]:=maxh-h[i]+1;
  ans:=max(ans,make);
  writeln(ans);
close(input);close(output);
end.
