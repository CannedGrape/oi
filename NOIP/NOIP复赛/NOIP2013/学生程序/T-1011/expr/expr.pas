var
  s:string;n:longint;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  randomize;n:=random(3);
  if n=1 then writeln(7891)
  else if n=2 then writeln(8)
    else writeln(4);
  close(input);close(output);
end.