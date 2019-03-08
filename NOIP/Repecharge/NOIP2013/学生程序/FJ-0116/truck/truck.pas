var
  i,j,k,n,m,q,x,y,z:longint;
  c:array[1..10000,1..10000] of longint;
  d:array[1..10000,1..10000] of boolean;
  f,g:array[1..10000] of longint;
begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    d[x,y]:=true;
    c[x,y]:=z;
  end;
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
        if (d[i,j]) and (d[j,k]) and (d[i,k]=false) then
        begin
          d[i,k]:=true;
          if c[i,j]<c[j,k] then c[i,k]:=c[i,j] else c[i,k]:=c[j,k];
          end;
  read(q);
   for i:=1 to q do
     readln(f[i],g[i]);
  for i:=1 to q do
    if d[f[i],g[i]] then writeln(c[f[i],g[i]])
    else writeln(-1);
  close(input); close(output);
end.
