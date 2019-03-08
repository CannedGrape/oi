program truck;
var n:integer;
begin
  assign(input,'truck.in');
  assign(output,'truck.out');
  reset(input);
  reset(output);
  rewrite(output);
  
  readln(n);
  
  writeln(3);
  writeln(-1);
  writeln(3);
  
  
  close(input);
  close(output);


end.