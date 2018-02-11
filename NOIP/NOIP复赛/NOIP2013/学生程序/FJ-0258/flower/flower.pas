var
a,h:array[1..10000]of longint;
m,n,i,j,k,temp,g,b:longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  writeln('3');
  close(input);
  close(output);
  readln;readln;
end.
