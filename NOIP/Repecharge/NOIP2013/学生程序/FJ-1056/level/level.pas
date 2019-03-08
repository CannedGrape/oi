var
  n,m,b,i,j:longint;
  a,c,s,max1,max2:array[1..1000]of longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  read(n,m);
  writeln(m);
  close(input);close(output);
end.
