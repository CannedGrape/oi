var
  a,b:longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(a,b);
  if b=2 then writeln(2);
  if b=3 then writeln(3);
  if (b<>2)and(b<>3) then writeln(b);
  close(input);
  close(output);
end.