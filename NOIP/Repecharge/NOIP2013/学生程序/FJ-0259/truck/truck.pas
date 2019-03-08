var
  a:array[1..10000,1..10000]of longint;
  i,x,y,z,m,n,q,s,w:longint;
begin
 assign(input,'truck.in');
 reset(input);
 assign(output,'truck.out');
 rewrite(output);
  readln(n,m);
  s:=0-(n*n+1);
  w:=1;
  for x:=1 to n do
  for y:=1 to n do
  a[x,y]:=-1;
  for i:=1 to m do
  begin
    readln(x,y,z);
    a[x,y]:=z;
    a[y,x]:=z;
  end;
  repeat
    for x:=1 to n do
    for y:=x+1 to n do
    for z:=y+1 to n do
    if( a[x,y]>a[x,z])and (a[y,z]>a[x,z])and(x<>y)and(x<>z)and(y<>z)then
    begin
      a[x,z]:=a[x,y];
      if a[x,y]>a[y,z]then a[x,z]:=a[y,z];
      a[z,x]:=a[x,z]
    end;
    w:=s;
    s:=0;
    for x:=1 to n do
    for y:=1 to n do
    s:=s+a[x,y]
   until s=w;
  readln(q);
  for i:=1 to q do
  begin
  readln(x,y);
  writeln(a[x,y]);
  end;
 readln;readln;
   close(input);
  close(output);
end.
