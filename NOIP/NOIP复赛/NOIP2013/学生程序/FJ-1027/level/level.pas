program level;
var
  a:array[1..1000,1..1000]of boolean;
  s:array[1..1000]of longint;
  g:array[1..1000,1..1000]of longint;
  z:array[1..1000]of longint;
  i,j,k,m,n,max:longint;
  procedure ast;
  begin
    for i:=1 to m do
      if g[i,s[i]]-g[i,1]+1=s[i] then s[i]:=0;
  end;
  procedure bing(x,y:longint);
  var
    f:boolean;
  begin
    f:=false;
    for i:=1 to s[x] do
    if not(a[x,g[x,i]] and a[y,g[x,i]]) or (s[y]=0) then begin f:=true; exit; end;
    if not(f) then s[x]:=0;
  end;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),false);
  readln(n,m);
  for i:=1 to m do
  begin
    read(s[i]);
    for j:=1 to s[i] do
    begin
      read(g[i,j]);
      a[i,g[i,j]]:=true;
    end;
  end;
  ast;
  for j:=1 to m do
    for k:=1 to m do
      if (s[k]>0) and (s[j]>0) and (j<>k) then bing(j,k);
  fillchar(z,sizeof(z),0);
  for i:=1 to n do
    for j:=1 to m do
    if (a[j,i]) and (s[j]>0) then inc(z[i]);
    max:=-maxlongint;
  for i:=1 to n do
  if z[i]>max then max:=z[i];
  writeln(max+1);
  close(input);
  close(output);
end.