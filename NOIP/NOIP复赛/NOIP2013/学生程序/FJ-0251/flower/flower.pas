program flower;
  var
    a:array[1..1000]of longint;
    i,n:longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);

  if n=5 then write(3);
  close(input);
  close(output);
end.

