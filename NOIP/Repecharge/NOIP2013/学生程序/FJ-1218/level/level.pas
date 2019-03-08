var a,b:array[0..1000,0..1000] of longint;
    c:array[1..1000,1..1000] of boolean;
    f:array[1..1000] of boolean;
    d:array[1..1000] of longint;
    n,m,i,j,k,x,xxx,ans:longint;
procedure qu(s,e:longint);
var i1,j1:longint;
begin
  for i1:=s to e do
  if not f[i1] then
  begin
    for j1:=1 to x do
    if not c[b[i,j1],i1] then
    begin
      inc(a[b[i,j1],0]);
      a[b[i,j1],a[b[i,j1],0]]:=i1;
      inc(d[i1]);
      c[b[i,j1],i1]:=true;
    end;
  end;
end;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(m,n);
  for i:=1 to n do
  begin
    fillchar(f,sizeof(f),false);
    read(x);
    for j:=1 to x do
    begin
      read(b[i,j]);
      f[b[i,j]]:=true;
    end;
    qu(b[i,1],b[i,x]);
    readln;
  end;
  fillchar(f,sizeof(f),true);
  xxx:=m;
  while xxx<>0 do
  begin
    for i:=1 to m do
    if (d[i]=0) and (f[i]) then
    begin
      f[i]:=false;
      for j:=1 to a[i,0] do
      if f[a[i,j]] then dec(d[a[i,j]]);
      dec(xxx);
    end;
    inc(ans);
  end;
  writeln(ans);
  close(input);close(output);
end.

