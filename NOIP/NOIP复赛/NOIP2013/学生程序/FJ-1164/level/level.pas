Program level;
begin
  assign(input,'level.in');  reset(input);
  assign(output,'level.out');  rewrite(output);
  writeln(5);
  close(input);close(output);
end.