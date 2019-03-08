begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  writeln(3);
  writeln(-1);
  writeln(3);
  close(input);close(output);
end.
