begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  close(input);
  close(output);
end.

