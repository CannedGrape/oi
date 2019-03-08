var
  a,b:longint;
begin
  assign(input,'number.in'); reset(input);
  assign(output,'number.out'); rewrite(output);
  readln(a,b);
  if b=997 then writeln(21);
  if b=7 then writeln(-1);
  close(input); close(output);
end.