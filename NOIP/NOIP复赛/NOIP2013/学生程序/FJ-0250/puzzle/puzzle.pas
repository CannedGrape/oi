program puzzle;
  var
  n,m,q:longint;
  a:array [1..1000,1..1000] of longint;
  b:array [1..10000,1..10000] of longint;
  begin
     read(n,m,q);
     for i:=1 to n do
     for j:=1 to m do
      read(a[i,j]);
      for i:=1 to q do
       for j:=1 to 6 do
          read(b[i,j]);

