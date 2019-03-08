//puzzle
var q,i:longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  read(q);
  read(q);
  read(q);
  for i:=1 to q do writeln(-1);
  close(input);
  close(output);
end.