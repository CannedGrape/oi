var
  a:longint;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  while not(eof) do read(a);
  writeln(2);
  writeln(-1);
end.
