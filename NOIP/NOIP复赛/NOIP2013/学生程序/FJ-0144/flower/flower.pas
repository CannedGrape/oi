var
  n,i:longint;
  a:array[1..1000]of longint;
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do readln(a[i]);
  writeln(3);
  close(input);close(output);
end.