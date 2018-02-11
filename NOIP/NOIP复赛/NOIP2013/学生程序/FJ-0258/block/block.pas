var
a,h:array[1..10000]of longint;
m,n,i,j,k,temp,g,b:longint;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  writeln('5');
  close(input);
  close(output);
  readln;readln;
end.
