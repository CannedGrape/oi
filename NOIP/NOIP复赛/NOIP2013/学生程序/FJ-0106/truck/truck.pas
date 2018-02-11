var n,m,q,i,ans,maxdeep,x,y,z,r1,r2,j,tot,k:longint;
    a:array[0..50500,1..3] of longint;
    deep,f,first:array[0..30000] of longint;
    endl,next,w:array[0..100000] of longint;
    v,fa:array[0..30000,0..40] of longint;
    bo,boo:array[0..40000] of boolean;

function min(x,y:longint):longint;
begin
    if x<y then exit(x);
    exit(y);
end;

procedure change(var x,y:longint);
var i:longint;
begin
    while deep[x]<>deep[y] do
    begin
     for i:=maxdeep downto 0 do
     begin
       if deep[fa[y,i]]>=deep[x] then
       begin
        ans:=min(ans,v[y,i]);
        y:=fa[y,i];
        break;
       end;
     end;
    end;
end;

procedure swap(var x,y:longint);
var t:longint;
begin
    t:=x; x:=y; y:=t;
end;

procedure zuijin(x,y:longint);
var i:longint;
begin
    if deep[x]>deep[y] then swap(x,y);
    if deep[x]<>deep[y] then
     change(x,y);
    if x=y then begin writeln(ans); exit; end;
    while fa[x,0]<>fa[y,0] do
    begin
     for i:=maxdeep downto 0 do
      if fa[x,i]<>fa[y,i] then
      begin
       ans:=min(ans,min(v[x,i],v[y,i]));
       x:=fa[x,i]; y:=fa[y,i];
       break;
      end;
    end;
    writeln(min(ans,min(v[x,0],v[y,0])));
end;

procedure go(x:longint);
var i,y:longint;
begin
    bo[x]:=true;
    i:=first[x];
    while i<>0 do
    begin
     y:=endl[i];
     if not bo[y] then
     begin
      fa[y,0]:=x;
      v[y,0]:=w[i];
      deep[y]:=deep[x]+1;
      go(y);
     end;
     i:=next[i];
    end;
end;

procedure jian(x,y,z:longint);
begin
     inc(tot);
     next[tot]:=first[x];
     first[x]:=tot;
     endl[tot]:=y;
     w[tot]:=z;
end;

function father(x:longint):longint;
begin
    if x=f[x] then exit(x);
    x:=father(f[x]);
    exit(x);
end;

procedure kp(l,r:longint);
var i,j,mid:longint;
begin
    i:=l; j:=r; mid:=a[(i+j)>>1,3];
    repeat
     while a[i,3]>mid do inc(i);
     while a[j,3]<mid do dec(j);
     if i<=j then
     begin
       swap(a[i,1],a[j,1]);
       swap(a[i,2],a[j,2]);
       swap(a[i,3],a[j,3]);
       inc(i); dec(j);
     end;
    until i>j;
    if i<r then kp(i,r);
    if l<j then kp(l,j);
end;

begin
    assign(input,'truck.in'); reset(input);
    assign(output,'truck.out'); rewrite(output);
    readln(n,m);
    for i:=1 to m do
    begin
     readln(x,y,z);
     a[i,1]:=x;
     a[i,2]:=y;
     a[i,3]:=z;
    end;
    kp(1,n);
    for i:=1 to n do
     f[i]:=i;
    for i:=1 to m do
    begin
      r1:=father(a[i,1]);
      r2:=father(a[i,2]);
      if r1<>r2 then
      begin
        f[r1]:=r2;
        inc(k);
        jian(a[i,1],a[i,2],a[i,3]);
        jian(a[i,2],a[i,1],a[i,3]);
      end;
      if k=n-1 then break;
    end;
    fillchar(bo,sizeof(bo),false);
    fillchar(v,sizeof(v),$3f);
    for i:=1 to n do
    begin
      if not bo[i] then
      begin
       deep[i]:=1;
       go(i);
       boo[i]:=true;
      end;
    end;
    maxdeep:=trunc(ln(n)/ln(2))+1;
    for j:=1 to maxdeep do
    begin
     for i:=1 to n do
      if not boo[i] then
      begin
        fa[i,j]:=fa[fa[i,j-1],j-1];
        v[i,j]:=min(v[i,j-1],v[fa[i,j-1],j-1]);
      end;
    end;
    readln(q);
    for i:=1 to q do
    begin
     readln(x,y);
     r1:=father(x);
     r2:=father(y);
     if r1<>r2 then
     begin
      writeln(-1);
      continue;
     end;
     ans:=maxlongint;
     zuijin(x,y);
    end;
    close(input); close(output);
end.
