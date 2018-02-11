var
 m:longint;
begin
assign(input,'level.in');
assign(output,'level.out');
rewrite(output);
reset(input);
  readln(m,m);
  if m=1 then m:=2;
  writeln(m);
close(input);
close(output);
end.
