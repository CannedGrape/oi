program level;
var i:integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  randomize;
  i:=random(10);
  write(i) ;
  close(input);  close(output);
end.