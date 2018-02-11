var
  a:array[0..10,0..10] of longint;
  ex,ey,sx,sy,tx,ty:array[1..100000] of longint;
  n,m,q,i,j,x:longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for x:=1 to q do
  read(ex[x],ey[x],sx[x],sy[x],tx[x],ty[x]);
  if a[i,j]=0 then exit;
  close(input);close(output);
end.
