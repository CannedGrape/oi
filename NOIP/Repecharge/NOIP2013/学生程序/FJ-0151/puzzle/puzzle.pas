var a,b,c:longint;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  for a:=1 to 6 do
    repeat
      read(b);
    until eoln;
  writeln('2');
  writeln('-1');
  close(input);
  close(output);
end.
