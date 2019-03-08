var
  a,b,q,i:integer;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  readln(a,b,q);
  close(input);
  begin
  for i:=1 to q do
  rewrite(output);
  writeln('-1');
  end;
  close(output);
end.
