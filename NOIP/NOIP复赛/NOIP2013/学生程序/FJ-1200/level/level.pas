program level;
var
  i,j,k,l,n,m,ans:longint;
  a,b:array[1..1000]of longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  while not eof do
  begin
    read(k);  l:=n;
    for i:=1 to k do
    begin read(a[i]); if l>a[i]then l:=a[i]; end;
    inc(j);
    b[j]:=l;
    if l>m then ans:=1;
  end;
    k:=b[1];
    if ans=1 then write(m)else begin'
    for i:=2 to j do
    if a[i]>k then k:=a[i];
    write(k);
    end;
    close(input);
    close(output);
end.
