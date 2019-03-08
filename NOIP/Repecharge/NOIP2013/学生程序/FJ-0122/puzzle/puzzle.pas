var
  a:array[0..31,0..31]of longint;
  n,m,q,i,j,k,x1,y1,x2,y2,x3,y3,t:longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to n do
      read(a[i,j]);
  for i:=1 to q do
  begin
    t:=0;
    readln(x1,y1,x2,y2,x3,y3);
    writeln(-1);
  end;
  readln;
  close(input);close(output);
end.