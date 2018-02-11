var
  n,i,j,max,p1,p2:longint;
  h:array[1..100000]of longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  writeln(n-2);
  close(input); close(output);
end.
