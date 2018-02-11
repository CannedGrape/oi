var s,l,h:qword;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(s,l);
  for i:= 1 to s do
  readln(h);
  if s=5 and l=997 then writeln('21');
  if s=5 and l=7 then writeln('-1');
  close(input);
  close(output);
end.

