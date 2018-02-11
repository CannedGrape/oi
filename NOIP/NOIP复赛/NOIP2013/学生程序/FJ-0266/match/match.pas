program match;
  const mo:int64=99999997;
  var num1,num2,num4,num5,a,b,c:array[1..100000]of longint;
      i,j,m,n,z,x,y:longint;
      ans:int64;
  procedure solve(p,q,t:longint);
  var i,j,k:longint;
  begin
    i:=p;j:=t+1;
    for k:=p to q do
    begin
      if (j>q)or((i<=t)and(num5[i]>num5[j])) then
      begin
        c[k]:=num5[i];ans:=(ans+(q-j+1))mod mo;inc(i);
      end
      else begin
        c[k]:=num5[j];inc(j);
      end;
    end;
    for k:=p to q do num5[k]:=c[k];
  end;
  procedure merge(l,r:longint);
  var mid:longint;
  begin
    if l>=r then exit;
    mid:=(l+r) div 2;
    merge(l,mid);
    merge(mid+1,r);
    solve(l,r,mid);
  end;
  procedure qsort1(l,r:longint);
  var i,j,mid,t:longint;
  begin
    i:=l;j:=r;mid:=a[(l+r)div 2];
    repeat
      while (a[i]<mid) do inc(i);
      while (a[j]>mid) do dec(j);
      if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        t:=num1[i];num1[i]:=num1[j];num1[j]:=t;
        inc(i);dec(j);
      end;
    until i>j;
    if i<r then qsort1(i,r);
    if l<j then qsort1(l,j);
  end;
  procedure qsort2(l,r:longint);
  var i,j,mid,t:longint;
  begin
    i:=l;j:=r;mid:=b[(l+r)div 2];
    repeat
      while (b[i]<mid) do inc(i);
      while (b[j]>mid) do dec(j);
      if i<=j then
      begin
        t:=b[i];b[i]:=b[j];b[j]:=t;
        t:=num2[i];num2[i]:=num2[j];num2[j]:=t;
        inc(i);dec(j);
      end;
    until i>j;
    if i<r then qsort2(i,r);
    if l<j then qsort2(l,j);
  end;
  begin
    assign(input,'match.in');assign(output,'match.out');
    reset(input);rewrite(output);
    read(m);
    for i:=1 to m do read(a[i]);
    for i:=1 to m do read(b[i]);
    for i:=1 to m do
    begin
      num1[i]:=i;num2[i]:=i;
    end;
    qsort1(1,m);
    qsort2(1,m);
    for i:=1 to m do num4[num2[i]]:=i;
    for i:=1 to m do num5[i]:=num1[num4[i]];
    merge(1,m);
    writeln(ans);
    close(input);close(output);
  end.
