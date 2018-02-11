program block;
  var a,num,b,c:array[1..100000]of longint;
      i,j,k,m,n,z,x,y,ans:longint;
  procedure qsort(l,r:longint);
  var i,j,mid,t:longint;
  begin
    i:=l;j:=r;mid:=a[(l+r) div 2];
    repeat
      while (a[i]<mid) do inc(i);
      while (a[j]>mid) do dec(j);
      if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        t:=num[i];num[i]:=num[j];num[j]:=t;
        inc(i);dec(j);
      end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
  end;
  begin
    assign(input,'block.in');assign(output,'block.out');
    reset(input);rewrite(output);
    read(m);
    for i:=1 to m do read(a[i]);
    b:=a;
    for i:=1 to m do num[i]:=i;
    qsort(1,m);
    ans:=0;
    for k:=1 to m do
    begin
      i:=num[k];j:=num[k];
      while (i>1)and(c[i-1]=0) do dec(i);
      while (j<m)and(c[j+1]=0) do inc(j);
      z:=0;
      if i>1 then z:=b[i-1];
      if (j<m)and(z<b[j+1]) then z:=b[j+1];
      ans:=ans+(b[num[k]]-z);
      c[num[k]]:=1;
    end;
    write(ans);
    close(input);close(output);
  end.
