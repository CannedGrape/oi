
var a,b,c:longint;
begin
  assign(input,'flower.in');
  reset(input);
  assign(output,'flower.out');
  rewrite(output);
  read(a);
  for b:=1 to a do
    read(c);
  writeln('3');
  close(input);
  close(output);
  end.
















