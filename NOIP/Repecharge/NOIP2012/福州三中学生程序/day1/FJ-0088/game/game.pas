const filename='game';maxn=1000;maxm=4000;maxt=10000;
type hugeint=record
  head:longint;
  data:array[1..maxm]of longint;
end;
var n,m,i,j,k:longint;
a,b:array[0..maxn]of longint;
total,max,ans,temp,max2:hugeint;

function big(a,b:hugeint):boolean;
var i,j:longint;
begin
  if a.head<b.head then exit(true)
  else if b.head<a.head then exit(false)
  else begin
    j:=a.head;
    for i:=a.head to maxm do
      if a.data[i]<>b.data[i] then exit(a.data[i]>b.data[i]);
  end;
  exit(false);
end;

procedure print(a:hugeint);
var i:longint;
begin
  with a do begin
    write(data[head]);
    for i:=head+1 to maxm do begin
      if data[i]<1000 then write(0);
      if data[i]<100 then write(0);
      if data[i]<10 then write(0);
      write(data[i]);
    end;
  end;
end;

function gcheng(a:hugeint;b:longint):hugeint;
var c:hugeint;x,i:longint;
begin
  x:=0;
  with c do begin
    for i:=maxm downto a.head do begin
      x:=x+a.data[i]*b;
      data[i]:=x mod maxt;
      x:=x div maxt;
    end;
    head:=a.head;
    while x>0 do begin
      dec(head);
      data[head]:=x mod maxt;
      x:=x div maxt;
    end;
  end;
  exit(c);
end;

function gdiv(a:hugeint;b:longint):hugeint;
var c:hugeint;x,i:longint;
begin
  x:=0;
  with c do begin
    head:=a.head;
    for i:=head to maxm do begin
      x:=x*maxt+a.data[i];
      data[i]:=x div b;
      x:=x mod b;
    end;
    while (data[head]=0)and(head<maxm) do inc(head);
  end;
  exit(c);
end;

procedure qsort(l,r:longint);
var i,j,x,y,z:longint;
begin
  i:=l;j:=r;
  x:=a[(l+r)shr 1];
  y:=b[(l+r)shr 1];
  while i<=j do begin
    while (a[i]<x)or((a[i]=x)and(b[i]<y)) do inc(i);
    while (x<a[j])or((x=a[j])and(y<b[j])) do dec(j);
    if i<=j then begin
      z:=a[i];a[i]:=a[j];a[j]:=z;
      z:=b[i];b[i]:=b[j];b[j]:=z;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;

procedure qsort2(l,r:longint);
var i,j,x,y,z:longint;
begin
  i:=l;j:=r;
  x:=a[(l+r)shr 1];
  y:=b[(l+r)shr 1];
  while i<=j do begin
    while (b[i]<y)or((b[i]=y)and(a[i]<x)) do inc(i);
    while (y<b[j])or((y=b[j])and(x<a[j])) do dec(j);
    if i<=j then begin
      z:=a[i];a[i]:=a[j];a[j]:=z;
      z:=b[i];b[i]:=b[j];b[j]:=z;
      inc(i);dec(j);
    end;
  end;
  if i<r then qsort2(i,r);
  if l<j then qsort2(l,j);
end;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  readln(n);
  read(a[0],b[0]);
  for i:=1 to n do
    read(a[i],b[i]);
  with ans do begin
    head:=1;
    data[1]:=9;
  end;

  with total do begin
    head:=maxm;
    data[maxm]:=a[0];
    while data[head]>=maxt do begin
      data[head-1]:=data[head] div maxt;
      data[head]:=data[head] mod maxt;
      dec(head);
    end;
  end;
  with max do begin
    head:=maxm;
    data[head]:=0;
  end;
  qsort(1,n);
  for i:=1 to n do begin
    temp:=gdiv(total,b[i]);
    if big(temp,max) then max:=temp;
    if i=n-2 then max2:=max;
    total:=gcheng(total,a[i]);
  end;
  if big(ans,max) then ans:=max;
  if n>2 then begin
    total:=gdiv(total,a[n]);
    total:=gdiv(total,a[n-1]);
    for i:=n downto n-1 do begin
      temp:=gdiv(total,b[i]);
      if big(temp,max2) then max2:=temp;
      total:=gcheng(total,a[i]);
    end;
  end;
  if big(ans,max2) then ans:=max2;


  with total do begin
    head:=maxm;
    data[maxm]:=a[0];
    while data[head]>=maxt do begin
      data[head-1]:=data[head] div maxt;
      data[head]:=data[head] mod maxt;
      dec(head);
    end;
  end;
  with max do begin
    head:=maxm;
    data[head]:=0;
  end;
  qsort2(1,n);
  for i:=1 to n do begin
    temp:=gdiv(total,b[i]);
    if big(temp,max) then max:=temp;
    if i=n-2 then max2:=max;
    total:=gcheng(total,a[i]);
  end;
  if big(ans,max) then ans:=max;
  if n>2 then begin
    total:=gdiv(total,a[n]);
    total:=gdiv(total,a[n-1]);
    for i:=n downto n-1 do begin
      temp:=gdiv(total,b[i]);
      if big(temp,max2) then max2:=temp;
      total:=gcheng(total,a[i]);
    end;
  end;
  if big(ans,max2) then ans:=max2;

  print(ans);

  close(input);close(output);
end.
