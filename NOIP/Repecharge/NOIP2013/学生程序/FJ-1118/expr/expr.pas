program expr;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  writeln(random(9999));
  close(input);
  close(output);
end.
