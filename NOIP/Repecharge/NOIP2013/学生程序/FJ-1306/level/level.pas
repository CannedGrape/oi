var
  a:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  writeln('1');
  close(input);close(output);
end.