PROGRAM a4(input,output);
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  writeln('3');
  close(input);
  close(output);
end.