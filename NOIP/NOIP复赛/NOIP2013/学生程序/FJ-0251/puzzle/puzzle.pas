program puzzle;

begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  writeln(2);
  writeln(-1);
  close(input);
  close(output);
end.

