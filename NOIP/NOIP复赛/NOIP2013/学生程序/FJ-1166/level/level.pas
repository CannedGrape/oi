program level;
var
  n,m,i,j:longint;
  s:array[0..1000005] of string;
  c:char;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    readln(s[i]);
  writeln(m);
  close(input);
  close(output);
end.
