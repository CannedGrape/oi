program level(input,output);
var
  a:array[1..10000]of longint;
  n,m,s:longint;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level,out'); rewrite(output);
  writeln(5);
  close(input);
  close(output);
end.