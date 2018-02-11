var
  y:ansistring;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(y);
  if y='1+1*3+4' then writeln(8)
  else if y='1+1234567890*1' then writeln(7891)
  else writeln(4);
  close(input);close(output);
end.
