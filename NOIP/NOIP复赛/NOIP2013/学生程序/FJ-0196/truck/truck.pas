//truck
var a,b:array[0..1000,0..1000] of longint;
  i,j,n,m,q,x,y,z,fl,l,r:longint;
  v,li,le:array[0..1000] of longint;
  ck:array[0..1000] of boolean;

procedure spfa(x:longint);
var i,j,t:longint;
begin
  ck[x]:=false;
  i:=le[x];
  while i<n+1 do
  begin
    t:=v[x];if a[x,i]<t then t:=a[x,i];
    if t>v[i] then
    begin
      v[i]:=t;
      if ck[i] then
      begin
        inc(r);if r=n then r:=0;
        li[r]:=i;
      end;
    end;
    i:=b[x,i];
  end;
  ck[x]:=true;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  fillchar(a,sizeof(a),0);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if z>a[x,y] then a[x,y]:=z;
    if z>a[y,x] then a[y,x]:=z;
  end;
  readln(q);
  for i:=1 to n do
  begin
    fl:=n+1;
    for j:=n downto 1 do
    begin
      if a[i,j]<>0 then
      begin
        b[i,j]:=fl;
        fl:=j;
      end;
    end;
    le[i]:=fl;
  end;
  for i:=1 to q do
  begin;
    readln(x,y);
    fillchar(ck,sizeof(ck),true);
    fillchar(v,sizeof(v),0);
    v[x]:=100000;
    l:=0;r:=1;li[r]:=x;
    while l<>r do
    begin
      inc(l);if l=n then l:=0; spfa(li[l]);
    end;
    if v[y]<>0 then writeln(v[y]) else writeln(-1);
  end;
end.