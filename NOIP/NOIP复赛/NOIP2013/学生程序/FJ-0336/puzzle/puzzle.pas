var a:array[1..30,1..30]of longint;
    ex,ey,sx,sy,tx,ty:array[1..500]of longint;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
    readln(a[i,j]);
  for i:=1 to q do
   for j:=1 to 6 do
    readln(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);

close(input);
close(output);
end.
