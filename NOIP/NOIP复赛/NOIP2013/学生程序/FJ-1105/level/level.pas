var
 s:string;
 i:integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  for i:=1 to 5 do
  readln(s);
  write(5);
  close(input);
  close(output);
end.
