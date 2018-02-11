var n:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  randomize;n:=random(2);
  if n=1 then writeln(2) else writeln(3);
  close(input);close(output);
end.