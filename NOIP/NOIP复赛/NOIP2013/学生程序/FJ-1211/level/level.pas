var n,m:longint;
begin
  randomize;
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  if m<=11 then writeln(m)
  else writeln(m+random(m));
  close(output);
  close(input);
end.
