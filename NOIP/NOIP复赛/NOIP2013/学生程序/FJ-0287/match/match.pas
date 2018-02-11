uses math;

var i,n,o,p,q,ans:dword;
    a,b,u,v:array[0..100000]of dword;

function maxa(x,y:dword):dword;

begin
  if a[x]>a[y]then exit(x)else exit(y);
end;

function maxb(x,y:dword):dword;

begin
  if b[x]>b[y]then exit(x)else exit(y);
end;

function mida(x,y,z:dword):dword;

begin
  exit(maxa(x,y)xor maxa(x,z)xor maxa(y,z));
end;

function midb(x,y,z:dword):dword;

begin
  exit(maxb(x,y)xor maxb(x,z)xor maxb(y,z));
end;

function mid(x,y,z:dword):dword;

begin
  exit(max(x,y)xor max(x,z)xor max(y,z));
end;

procedure sorta(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  o:=mida(l,(i+j)>>1,r);
  p:=a[o];
  q:=u[o];
  repeat
    while(a[i]<p)or(a[i]=p)and(u[i]<q)do inc(i);
    while(a[j]>p)or(a[j]=p)and(u[j]>q)do dec(j);
    if i<=j then
    begin
      o:=a[i];
      a[i]:=a[j];
      a[j]:=o;
      o:=u[i];
      u[i]:=u[j];
      u[j]:=o;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sorta(l,j);
  if i<r then sorta(i,r);
end;

procedure sortb(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  o:=midb(l,(i+j)>>1,r);
  p:=b[o];
  q:=v[o];
  repeat
    while(b[i]<p)or(b[i]=p)and(v[i]<q)do inc(i);
    while(b[j]>p)or(b[j]=p)and(v[j]>q)do dec(j);
    if i<=j then
    begin
      o:=b[i];
      b[i]:=b[j];
      b[j]:=o;
      o:=v[i];
      v[i]:=v[j];
      v[j]:=o;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sortb(l,j);
  if i<r then sortb(i,r);
end;

procedure sort(l,r:dword);
var i,j:dword;

begin
  i:=l;
  j:=r;
  p:=mid(b[l],b[(i+j)>>1],b[r]);
  repeat
    while b[i]<p do inc(i);
    while b[j]>p do dec(j);
    if i<=j then
    begin
      q:=a[i];
      a[i]:=a[j];
      a[j]:=q;
      q:=b[i];
      b[i]:=b[j];
      b[j]:=q;
      inc(i);
      dec(j);
    end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;

procedure last(l,r:dword);
var mid:dword;

begin
  if l<r then
  begin
    mid:=(l+r)>>1;
    last(l,mid);
    last(mid+1,r);
    i:=l;
    p:=l;
    q:=mid+1;
    repeat
      if(q>r)or(p<=mid)and(a[p]<=a[q])then
      begin
        b[i]:=a[p];
        inc(p);
      end else
      begin
        b[i]:=a[q];
        inc(ans,mid-p+1);
        ans:=ans mod 99999997;
        inc(q);
      end;
      inc(i);
    until i>r;
    for i:=l to r do a[i]:=b[i];
  end;
end;

begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    read(a[i]);
    u[i]:=i;
  end;
  sorta(1,n);
  for i:=1 to n do
  begin
    read(b[i]);
    v[i]:=i;
  end;
  sortb(1,n);
  for i:=1 to n do
  begin
    a[u[i]]:=i;
    b[v[i]]:=i;
  end;
  sort(1,n);
  last(1,n);
  writeln(ans);
  close(input);
  close(output);
end.