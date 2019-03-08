var
  a,b,c:array[1..100000]of longint;
  n,i,r,x,y,z,o:longint;
begin
    assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  readln(n);
  o:=0;
  for i:=1 to n do read(c[i]);
  for i:=n downto 1 do
  begin
  x:=1;
  for r:=2 to n do  if  c[r]>c[x] then x:=r;
  a[x]:=i;
  c[x]:=0;
  end;
  readln;
  for i:=1 to n do read(c[i]);
  for i:=n downto 1 do
  begin
  x:=1;
  for r:=2 to n do  if  c[r]>c[x] then x:=r;
  b[x]:=i;
  c[x]:=0;
  end;
  for i:=1 to n do
  begin
  for r:=1 to n do if b[r]=a[i] then x:=r;
  y:=x-i;
  for r:=0 to y-1 do
  begin
  z:=b[x-r];
  b[x-r]:=b[x-r-1];
  b[x-r-1]:=z;
  o:=0+1
  end
  end;
  write(o mod 99999997);
  readln;readln;
    close(input);
  close(output);
end.
