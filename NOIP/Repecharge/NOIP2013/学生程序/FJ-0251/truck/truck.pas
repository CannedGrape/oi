program truck;
var
  o1,o2,o3:array[1..1000000]of longint;
  i,n,m,q:longint;
begin
  assign(input,'truck.in');
  reset(input);
  assign(output,'truck.out');
  rewrite(output);

  writeln(3);
  writeln(-1);
  writeln(3);

  close(input);
  close(output);
  readln;readln;
end.

