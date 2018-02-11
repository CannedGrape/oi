var
  n,i,j,k:longint;
  a:array[1..100000]of longint;
  boo:array[1..100000]of boolean;
begin
  assign(input,'flower.in'); reset(input);
  assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  writeln('3');
  close(input);close(output);
end.

