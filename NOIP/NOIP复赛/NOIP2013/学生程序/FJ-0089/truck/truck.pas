var
  a:array[1..5000,1..5000]of longint;
  i,j,l,k,x,y,z,n,m,q,t:longint;
  b,c:array[1..10000]of longint;
procedure bj(i,j:longint);
begin
  if i<j then l:=i
  else l:=j;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do
    for j:=1 to n do
  a[i,j]:=0;
  for i:=1 to m do
  begin
    readln(x,y,z);
    a[x,y]:=z;
    a[y,x]:=z;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(b[i],c[i]);
  end;
  for i:=1 to n do
    for j:=1 to n do
      for k:=1 to n do
      begin
        if (a[i,k]>0) and (a[k,j]>0) then
        begin
        bj(a[i,k],a[k,j]);
        if l>a[i,j] then a[i,j]:=l;
        end;
      end;
  for i:=1 to q do
  begin
    if a[b[i],c[i]]<>0 then writeln(a[b[i],c[i]])
    else writeln(-1);
    end;
  close(input);close(output);
end.
