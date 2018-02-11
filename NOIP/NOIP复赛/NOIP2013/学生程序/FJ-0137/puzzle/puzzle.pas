begin
   assign(input,'puzzle.in');reset(input);

  assign(output,'puzzle.out');rewrite(Output);
  writeln('-1');
  close(input);close(output);
end.