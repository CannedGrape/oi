var n,m,i,j,ans:longint;
    a:array[1..1000,1..1000]of longint;
    l,k:array[1..1000]of longint;
  function max(x,y:longint):longint;
  begin
    if x>y then exit(x);exit(y);
  end;
  function find(x,y:longint):longint;
  var i,t:longint;
  begin
    t:=0;
    for i:=x to y do
      if (l[i]>=l[x])or(l[i]>=l[y]) then inc(t);
    exit(t);
  end;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
    readln(n,m);
    for i:=1 to m do
    begin
      read(k[i]);
      for j:=1 to k[i] do read(a[i,j]);
    end;
    for i:=1 to n do l[i]:=1;
    for i:=1 to m do
    begin
      if k[i]<>find(a[i,1],a[i,k[i]]) then
      begin inc(l[a[i,1]]);inc(l[a[i,k[i]]]);end;
      for j:=2 to k[i]-1 do
        if l[a[i,j]]<max(l[a[i,1]],l[a[i,k[i]]]) then
           l[a[i,j]]:=max(l[a[i,1]],l[a[i,k[i]]]);
    end;
    for i:=1 to n do
      if l[i]>ans then ans:=l[i];
    writeln(ans);
  close(input);close(output);
end.
