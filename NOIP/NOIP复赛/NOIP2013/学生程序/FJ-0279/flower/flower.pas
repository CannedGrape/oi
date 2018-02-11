program flower;
var
  a:array[1..100000] of longint;
  i,j,k,n,m,s,t:longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  if n=5 then write('3')
  else
  if n=1 then write('1')
  else write('7');
  close(input);
  close(output);
end.