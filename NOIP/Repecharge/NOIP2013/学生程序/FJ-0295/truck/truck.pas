program truck;
var a,b,len,f:array[1..50000]of longint;
    edge:array[1..10000]of record
                             s,e,l:longint;
                           end;
    bo:array[1..10000]of boolean;
    n,m,q,x,y,i,ans,min,cnt:longint;
procedure qsort(l,r:longint);
var i,j,m,p:longint;
begin
    i:=l;   j:=r;   m:=len[(l+r) div 2];
    repeat
      while len[i]>m do inc(i);
      while len[j]<m do dec(j);
      if i<=j then
      begin
        p:=len[i];   len[i]:=len[j];   len[j]:=p;
        p:=a[i];   a[i]:=a[j];   a[j]:=p;
        p:=b[i];   b[i]:=b[j];   b[j]:=p;
        inc(i);   dec(j);
      end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
end;
function find(x:longint):longint;
begin
    if f[x]=x then exit(x);
    f[x]:=find(f[x]);
    exit(f[x]);
end;
procedure union(x,y:longint);
var fx,fy:longint;
begin
    fx:=find(x);
    fy:=find(y);
    f[fy]:=fx;
end;
procedure kruscal;
var i:longint;
begin
    for i:=1 to n do f[i]:=i;
    cnt:=0;
    for i:=1 to m do
      if find(a[i])<>find(b[i]) then
      begin
        union(a[i],b[i]);
        inc(cnt);
        edge[cnt].s:=a[i];
        edge[cnt].e:=b[i];
        edge[cnt].l:=len[i];
        if cnt=n-1 then break;
      end;
end;
procedure search(st:longint);
var i,p:longint;
begin
    if st=y then
    begin
      if ans<min then min:=ans;
      exit;
    end;
    bo[st]:=false;
    p:=ans;
    for i:=1 to cnt do
    begin
      if (st=edge[i].s) and (bo[edge[i].e]) then
      begin
        if edge[i].l<ans then ans:=edge[i].l;
        search(edge[i].e);
        bo[edge[i].e]:=true;
        ans:=p;
      end;
      if (st=edge[i].e) and (bo[edge[i].s]) then
      begin
        if edge[i].l<ans then ans:=edge[i].l;
        search(edge[i].s);
        bo[edge[i].s]:=true;
        ans:=p;
      end;
    end;
end;
begin
    assign(input,'truck.in');
    assign(output,'truck.out');
    reset(input);
    rewrite(output);
    readln(n,m);
    for i:=1 to m do readln(a[i],b[i],len[i]);
    qsort(1,m);
    kruscal;
    readln(q);
    for i:=1 to q do
    begin
      fillchar(bo,sizeof(bo),true);
      readln(x,y);
      if find(x)<>find(y) then writeln('-1')
      else
      begin
        min:=maxlongint;
        ans:=maxlongint;
        search(x);
        writeln(min);
      end;
    end;
    close(input);
    close(output);
end.
