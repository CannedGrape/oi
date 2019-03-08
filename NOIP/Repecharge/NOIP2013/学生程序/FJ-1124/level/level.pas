var
  n,m:longint;
  a:array[0..1000,1..1000] of longint;
  b,e:array[1..1000] of longint;
  ans:longint;
  bx,ex:longint;
  i,j,s,t:longint;
  z,y:longint;
  f:boolean;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
    read(s);
    b[i]:=maxlongint;
    for j:=1 to s do
      begin
      read(t); a[i,t]:=1;
      if t<b[i] then b[i]:=t;
      if t>e[i] then e[i]:=t;
      end;
    readln;
    end;
  f:=true;
  for i:=b[1] to e[1] do if a[1,i]=0 then begin f:=false; break; end;
  if f then ans:=1 else ans:=2;
  bx:=b[1]; ex:=e[1];
  for i:=2 to m do
    begin
    f:=true;
    for j:=b[i] to e[i] do if a[i,j]=0 then begin f:=false; break; end;
    if f then continue;
    f:=true;
    if (bx<=b[i]) and (ex>=e[i]) then
    for j:=b[i] to e[i] do
      if a[i,j]<>a[i-1,j] then begin f:=false; break; end;
    if (b[i]<=bx) and (e[i]>=ex) then
    for j:=bx to ex do
      if a[i,j]<>a[i-1,j] then begin f:=false; break; end;
    if (b[i]<bx) and (bx<e[i]) and (e[i]<ex) then
    for j:=bx to e[i] do
      if a[i,j]<>a[i-1,j] then begin f:=false; break; end;
    if (bx<b[i]) and (b[i]<ex) and (ex<e[i]) then
    for j:=b[i] to ex do
      if a[i,j]<>a[i-1,j] then begin f:=false; break; end;
    if not f then inc(ans);
    if b[i]<bx then bx:=b[i];
    if e[i]>ex then ex:=e[i];
    for j:=1 to n do
      if a[i-1,j]=1 then a[i,j]:=1;
    end;
  writeln(ans);
  close(input);
  close(output);
end.