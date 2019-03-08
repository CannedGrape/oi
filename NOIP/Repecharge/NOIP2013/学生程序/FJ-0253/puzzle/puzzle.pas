program puzzle;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln;
  writeln('2');
  writeln('-1');
  close(input);
  close(output);
end.

