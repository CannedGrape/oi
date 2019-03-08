program truck;
  var a:array[1..100000,1..4]of longint;
      question:array[1..30000,1..2]of longint;
      b,beg,last:array[1..10000]of longint;
      c:array[1..10000]of boolean;
      d:array[1..1000000]of longint;
      ans,numans:array[1..30000]of longint;
      i,j,m,n,z,x,y,q,num,t:longint;
  procedure qsort(l,r:longint);
  var i,j,mid,t:longint;
  begin
    i:=l;j:=r;mid:=question[(l+r)div 2,1];
    repeat
      while (question[i,1]<mid) do inc(i);
      while (question[j,1]>mid) do dec(j);
      if i<=j then
      begin
        t:=question[i,1];question[i,1]:=question[j,1];question[j,1]:=t;
        t:=question[i,2];question[i,2]:=question[j,2];question[j,2]:=t;
        t:=numans[i];numans[i]:=numans[j];numans[j]:=t;
        inc(i);dec(j);
      end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
  end;
  function min(a,b:longint):longint;
  begin
    if a>b then exit(b);exit(a);
  end;
  procedure spfa(l:longint);
  var i,j,h,t,td:longint;
  begin
    d[1]:=l;
    fillchar(c,sizeof(c),false);c[l]:=true;
    for i:=1 to n do b[i]:=-1;
    b[l]:=maxlongint;
    h:=0;t:=1;
    repeat
      inc(h);
      j:=beg[d[h]];
      while j<>0 do
      begin
        td:=a[j,2];
        if b[td]<min(b[d[h]],a[j,3]) then
        begin
          b[td]:=min(b[d[h]],a[j,3]);
          if c[td]=false then
          begin
            inc(t);d[t]:=td;c[td]:=true;
          end;
        end;
        j:=a[j,4];
      end;
      c[d[h]]:=false;
    until h>=t;
  end;
  begin
    assign(input,'truck.in');assign(output,'truck.out');
    reset(input);rewrite(output);
    read(n,m);
    for i:=1 to m do
    begin
      read(x,y,z);
      a[i*2-1,1]:=x;a[i*2-1,2]:=y;a[i*2-1,3]:=z;
      if last[x]=0 then beg[x]:=i*2-1
      else a[last[x],4]:=i*2-1;
      last[x]:=i*2-1;
      a[i*2,1]:=y;a[i*2,2]:=x;a[i*2,3]:=z;
      if last[y]=0 then beg[y]:=i*2
      else a[last[y],4]:=i*2;
      last[y]:=i*2;
    end;
    read(q);
    for i:=1 to q do
    begin
      read(question[i,1],question[i,2]);
      if question[i,1]>question[i,2] then
      begin
        t:=question[i,1];question[i,1]:=question[i,2];question[i,2]:=t;
      end;
      numans[i]:=i;
    end;
    qsort(1,q);
    num:=0;
    for i:=1 to q do
    begin
      if question[i,1]=num then ans[numans[i]]:=b[question[i,2]]
      else begin
        num:=question[i,1];
        spfa(question[i,1]);
        ans[numans[i]]:=b[question[i,2]];
      end;
    end;
    for i:=1 to q do writeln(ans[i]);
    close(input);close(output);
  end.
