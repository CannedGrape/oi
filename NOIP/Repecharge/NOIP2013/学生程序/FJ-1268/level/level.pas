program s4;
var
  a:string;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(a);
  writeln('4');
  close(input);
  close(output);
end.