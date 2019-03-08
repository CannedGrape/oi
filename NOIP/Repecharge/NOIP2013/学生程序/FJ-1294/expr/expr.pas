program expr;
var
  i:integer;
  s:string;
begin
assign(input,'expr.in'); reset(input);
assign(output,'expr.out'); rewrite(output);
  read(s);
  randomize;
  i:=random(10);
  write(i);
  close(input);
  close(output);
end.

