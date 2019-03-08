var a,b,c,d:array[0..100000]of longint;
    w:array[0..10000]of longint;
    x,y,z,i,j,n,m,q,t,s,min:longint;

  procedure add(x,y,z:longint);
  begin
    inc(t);
    a[t]:=y;
    b[t]:=z;
    c[t]:=d[x];
    d[x]:=t;
  end;

  procedure st(k:longint);
  var j,ss:longint;
  begin
    if k=y then
      begin
        if (s<>maxlongint)and(s>min) then min:=s;
        exit;
      end;
    if s<min then exit;
    j:=d[k];
    while j<>0 do
      begin
        if w[a[j]]=0 then
          begin
            w[a[j]]:=1;
            ss:=s;
            if b[j]<s then s:=b[j];
            st(a[j]);
            w[a[j]]:=0;
            s:=ss;
          end;
        j:=c[j];
      end;
  end;

begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  t:=0;
  for i:=1 to m do
  begin
    readln(x,y,z);
    add(x,y,z);
    add(y,x,z);
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    fillchar(w,sizeof(w),0);
    w[x]:=1;
    min:=-1;s:=maxlongint;
    st(x);
    writeln(min);
  end;
  close(input);close(output);
end.
