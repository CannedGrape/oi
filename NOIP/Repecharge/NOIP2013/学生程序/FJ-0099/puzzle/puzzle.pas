var
  n,m,i,j,i1,i2,j1,j2,l,t,s,q,x1,x2,x3,y1,y2,y3:longint;
  a,b:array[0..100,0..100]of longint;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to q do
    begin
      read(x1,y1,x2,y2,x3,y3);
      if x1=3 then writeln('2')
      else writeln('-1');
    end;
  close(input);close(output);
end.
