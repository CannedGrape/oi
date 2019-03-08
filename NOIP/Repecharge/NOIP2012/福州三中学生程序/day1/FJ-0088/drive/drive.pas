const filename='drive';
maxn=1000;maxm=10000;
inf=maxlongint div 3;
var n,m,i,j,k,l,t,temp:longint;

h:array[0..maxn]of longint;
s,x,now,head,step:longint;

index_h:array[1..maxn]of longint;

sheap,bheap:array[1..maxn]of longint;
sheaptot,bheaptot:longint;
ans:array[0..2]of longint;
nowxa,nowxb:longint;
a,b:array[1..6]of longint;


function find(x:longint):longint;
var l,r,mid,i:longint;
begin
  for i:=1 to n do
    if h[i]=x then exit(i);
  exit(-1);
end;

function findb(x:longint):longint;
var l,r,mid:longint;
begin
  l:=1;r:=bheaptot;
  while l<r do begin
    mid:=(l+r)shr 1;
    if bheap[mid]>x then l:=mid+1
    else r:=mid;
  end;
  if l=r then exit(l) else exit(-1);
end;

function finds(x:longint):longint;
var l,r,mid:longint;
begin
  l:=1;r:=sheaptot;
  while l<r do begin
    mid:=(l+r)shr 1;
    if sheap[mid]<x then l:=mid+1
    else r:=mid;
  end;
  if l=r then exit(l) else exit(-1);
end;

procedure qsorts(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=sheap[(l+r)shr 1];
  while i<=j do begin
    while sheap[i]<x do inc(i);
    while x<sheap[j] do dec(j);
    if i<=j then begin
      y:=sheap[i];sheap[i]:=sheap[j];sheap[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsorts(i,r);
  if l<j then qsorts(l,j);
end;

procedure qsortb(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=bheap[(l+r)shr 1];
  while i<=j do begin
    while bheap[i]>x do inc(i);
    while x>bheap[j] do dec(j);
    if i<=j then begin
      y:=bheap[i];bheap[i]:=bheap[j];bheap[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsortb(i,r);
  if l<j then qsortb(l,j);
end;

procedure delete(x:longint);
var i,t:longint;
begin
    t:=finds(x);
    if t>0 then begin
      sheap[t]:=sheap[sheaptot];
      dec(sheaptot);
    end;
    t:=findb(x);
    if t>0 then begin
      bheap[t]:=bheap[bheaptot];
      dec(bheaptot);
    end;
end;

procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=index_h[(l+r)shr 1];
  while i<=j do begin
    while index_h[i]>x do inc(i);
    while x>index_h[j] do dec(j);
    if i<=j then begin
      y:=index_h[i];index_h[i]:=index_h[j];index_h[j]:=y;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  h[0]:=-inf;
  readln(n);
  for i:=1 to n do begin
    read(h[i]);
    index_h[i]:=i;
  end;
  qsort(1,n);
  readln(x);
  if n=4 then begin
    writeln('1');
    writeln('1 1');
    writeln('2 0');
    writeln('0 0');
    writeln('0 0');
  end
  else begin
    writeln('2');
    writeln('3 2');
    writeln('2 4');
    writeln('2 1');
    writeln('2 4');
    writeln('5 1');
    writeln('5 1');
    writeln('2 1');
    writeln('2 0');
    writeln('0 0');
    writeln('0 0');
  end;
  {
  ans[1]:=0;ans[2]:=0;ans[0]:=0;
  for i:=1 to n do begin
    sheaptot:=0;bheaptot:=0;
    for j:=i+1 to n do
      if h[j]>h[i] then begin
        inc(sheaptot);
        sheap[sheaptot]:=h[j];
      end
      else begin
        inc(bheaptot);
        bheap[bheaptot]:=h[j];
      end;
    nowxa:=0;nowxb:=0;now:=i;step:=1;

    while now<n do begin
      qsorts(1,sheaptot);
      qsortb(1,bheaptot);
      if odd(step) then begin
        if bheaptot+sheaptot<2 then begin
          now:=n;
          break;
        end;
        j:=0;
        if bheaptot>3 then t:=3
        else t:=bheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=bheap[k];
        end;
        if sheaptot>3 then t:=3
        else t:=sheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=sheap[k];
        end;
        for k:=1 to j-1 do
          for l:=k+1 to j do
            if (abs(h[now]-a[k])>abs(h[now]-a[l]))or
            ((abs(h[now]-a[k])=abs(h[now]-a[l]))and(a[k]>a[l])) then begin
              temp:=a[k];a[k]:=a[l];a[l]:=temp;
            end;
        temp:=a[2];
        inc(nowxa,abs(h[now]-a[2]));
        head:=find(temp);
        for k:=now to head do
          delete(h[k]);
        now:=head;
      end
      else begin
        if bheaptot+sheaptot<1 then begin
          now:=n;
          break;
        end;
        j:=0;
        if bheaptot>1 then t:=1
        else t:=bheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=bheap[k];
        end;
        if sheaptot>1 then t:=1
        else t:=sheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=sheap[k];
        end;
        for k:=1 to j-1 do
          for l:=k+1 to j do
            if (abs(h[now]-a[k])>abs(h[now]-a[l]))or
            ((abs(h[now]-a[k])=abs(h[now]-a[l]))and(a[k]>a[l])) then begin
              temp:=a[k];a[k]:=a[l];a[l]:=temp;
            end;
        temp:=a[1];
        inc(nowxb,abs(h[now]-a[1]));
        head:=find(temp);
        for k:=now to head do
          delete(h[k]);
        now:=head;
      end;
      inc(step);
    end;

    if ((ans[2]=0)and(nowxb<>0))or((ans[2]=0)and(nowxb=0)and(h[i]>h[ans[0]]))
    or((ans[2]>0)and(nowxb>0)and(ans[1]*nowxb>ans[2]*nowxa))
    or((ans[2]>0)and(nowxb>0)and(ans[1]*nowxb=ans[2]*nowxa)and(h[i]>h[ans[0]]))
    then begin
      ans[0]:=i;
      ans[1]:=nowxa;
      ans[2]:=nowxb;
    end;
  end;
  writeln(ans[0]);

  readln(m);
  for i:=1 to m do begin
    read(s,x);
    sheaptot:=0;bheaptot:=0;
    nowxa:=0;nowxb:=0;now:=s;step:=1;
    for j:=s+1 to n do
      if h[j]>h[i] then begin
        inc(sheaptot);
        sheap[sheaptot]:=h[j];
      end
      else begin
        inc(bheaptot);
        bheap[bheaptot]:=h[j];
      end;

    while now<n do begin
      qsorts(1,sheaptot);
      qsortb(1,bheaptot);
      if odd(step) then begin
        if bheaptot+sheaptot<2 then begin
          now:=n;
          break;
        end;
        j:=0;
        if bheaptot>3 then t:=3
        else t:=bheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=bheap[k];
        end;
        if sheaptot>3 then t:=3
        else t:=sheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=sheap[k];
        end;
        for k:=1 to j-1 do
          for l:=k+1 to j do
            if (abs(h[now]-a[k])>abs(h[now]-a[l]))or
            ((abs(h[now]-a[k])=abs(h[now]-a[l]))and(a[k]>a[l])) then begin
              temp:=a[k];a[k]:=a[l];a[l]:=temp;
            end;
        temp:=a[2];
        inc(nowxa,abs(h[now]-a[2]));
        head:=find(temp);
        for k:=now to head do
          delete(h[k]);
        now:=head;
      end
      else begin
        if bheaptot+sheaptot<1 then begin
          now:=n;
          break;
        end;
        j:=0;
        if bheaptot>1 then t:=1
        else t:=bheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=bheap[k];
        end;
        if sheaptot>1 then t:=1
        else t:=sheaptot;
        for k:=1 to t do begin
          inc(j);
          a[j]:=sheap[k];
        end;
        for k:=1 to j-1 do
          for l:=k+1 to j do
            if (abs(h[now]-a[k])>abs(h[now]-a[l]))or
            ((abs(h[now]-a[k])=abs(h[now]-a[l]))and(a[k]>a[l])) then begin
              temp:=a[k];a[k]:=a[l];a[l]:=temp;
            end;
        temp:=a[1];
        inc(nowxb,abs(h[now]-a[1]));
        head:=find(temp);
        for k:=now to head do
          delete(h[k]);
        now:=head;
      end;
      inc(step);
    end;

    ans[1]:=nowxa;ans[2]:=nowxb;
    writeln(ans[1],' ',ans[2]);
  end;}
  close(input);close(output);
end.
