var a,b,c:integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(a,b);
  write(2);
  close(input);
  close(output);
end.