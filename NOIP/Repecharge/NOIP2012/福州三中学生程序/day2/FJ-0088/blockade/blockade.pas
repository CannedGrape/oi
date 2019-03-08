const filename='blockade';maxn=10000;maxm=30000;maxt=10000;
var n,m,i,j,k:longint;

v:array[1..maxn]of longint;
fto,next,cost:array[1..maxm]of longint;
x,y,z,num:longint;

p:array[1..maxt]of longint;

q,dep,father,gf:array[1..maxn]of longint;
head,tail,now,aim:longint;

cover,po:array[1..maxn]of boolean;
max_dep,max_T,g,c,count,root,bak:longint;
ct,ft,tree,from:array[0..maxn]of longint;

l,r,mid:longint;

procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=dep[p[(l+r)shr 1]];
  while i<=j do begin
    while dep[p[i]]>x do inc(i);
    while x>dep[p[j]] do dec(j);
    if i<=j then begin
      y:=p[i];p[i]:=p[j];p[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

procedure qsort2(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=tree[(l+r)shr 1];
  while i<=j do begin
    while tree[i]<x do inc(i);
    while x<tree[j] do dec(j);
    if i<=j then begin
      y:=tree[i];tree[i]:=tree[j];tree[j]:=y;
      y:=from[i];from[i]:=from[j];from[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort2(i,r);
  if l<j then qsort2(l,j);
end;

procedure qsort3(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=ct[(l+r)shr 1];
  while i<=j do begin
    while ct[i]<x do inc(i);
    while x<ct[j] do dec(j);
    if i<=j then begin
      y:=ct[i];ct[i]:=ct[j];ct[j]:=y;
      y:=ft[i];ft[i]:=ft[j];ft[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort3(i,r);
  if l<j then qsort3(l,j);
end;

function check(limit:longint):boolean;
var c:longint;
begin
  cover:=po;
  count:=0;ct[0]:=0;
  for i:=1 to m do begin
    g:=p[i];
    c:=0;
    while (c+gf[g]<=limit)and(father[g]>=1) do begin
      bak:=g;
      inc(c,gf[g]);
      g:=father[g];
    end;
    if g>1 then begin
      head:=1;tail:=1;
      q[1]:=g;
      while head<=tail do begin
        now:=q[head];inc(head);
        j:=v[now];
        while j>0 do begin
          aim:=fto[j];
          if not(cover[aim]) then begin
            cover[aim]:=true;
            if dep[aim]=max_dep then inc(count);
            inc(tail);
            q[tail]:=aim;
          end;
          j:=next[j];
        end;
      end;
    end
    else begin
      inc(ct[0]);
      ct[ct[0]]:=limit-c;
      ft[ct[0]]:=bak;
    end;
  end;
  if (ct[0]>0)and(count<max_T) then begin
    qsort3(1,ct[0]);
    i:=1;
    j:=1;
    while (i<=ct[0])and(j<=root) do begin
      while cover[from[j]] do inc(j);
      while (i<=ct[0])and(j<=root)and((ft[i]=from[j])or(ct[i]>=tree[j])) do begin
        inc(i);inc(j);
        while cover[from[j]] do inc(j);
      end;
      inc(i);
    end;
    if j>root then exit(true);
    for i:=1 to j-1 do begin
      head:=1;tail:=1;
      q[1]:=from[i];
      while head<=tail do begin
        now:=q[head];inc(head);
        k:=v[now];
        while k>0 do begin
          aim:=fto[k];
          if (not(cover[aim]))and(father[aim]=now) then begin
            cover[aim]:=true;
            if dep[aim]=max_dep then inc(count);
            inc(tail);
            q[tail]:=aim;
          end;
          k:=next[k];
        end;
      end;
    end;
  end;
  exit(count>=max_T);
end;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  readln(n);
  num:=0;
  for i:=1 to n-1 do begin
    read(x,y,z);
    inc(num);
    next[num]:=v[x];
    fto[num]:=y;
    cost[num]:=z;
    v[x]:=num;
    inc(num);
    next[num]:=v[y];
    fto[num]:=x;
    cost[num]:=z;
    v[y]:=num;
    if (x=1)or(y=1) then begin
      inc(root);
      tree[root]:=z;
      from[root]:=x+y-1;
    end;
  end;
  qsort2(1,root);


  head:=1;tail:=1;
  father[1]:=-1;
  q[1]:=1;dep[1]:=0;
  while head<=tail do begin
    now:=q[head];
    inc(head);
    j:=v[now];
    while j>0 do begin
      aim:=fto[j];
      if father[aim]=0 then begin
        father[aim]:=now;
        gf[aim]:=cost[j];
        dep[aim]:=dep[now]+1;
        if dep[aim]>max_dep then begin
          max_dep:=dep[aim];
          max_T:=1;
        end
        else if dep[aim]=max_dep then begin
          inc(max_T);
        end;
        inc(tail);
        q[tail]:=aim;
      end;
      j:=next[j];
    end;
  end;

  readln(m);

  if m<root then begin
    writeln(-1);
    close(input);
    close(output);
    halt;
  end;

  for i:=1 to m do read(p[i]);
  qsort(1,m);
  for i:=1 to m do begin
    head:=1;tail:=1;
    q[1]:=p[i];
    while head<=tail do begin
      now:=q[head];inc(head);
      po[now]:=true;
      j:=v[now];
      while j>0 do begin
        aim:=fto[j];
        if (not(po[aim]))and(father[aim]=now) then begin
          if dep[aim]=max_dep then dec(max_T);
          inc(tail);
          q[tail]:=aim;
        end;
        j:=next[j];
      end;
    end;
  end;

  l:=0;r:=maxlongint div 2;
  while l<r do begin
    mid:=(l+r)shr 1;
    if check(mid) then r:=mid
    else l:=mid+1;
  end;

  writeln(l);

  close(input);close(output);
end.
