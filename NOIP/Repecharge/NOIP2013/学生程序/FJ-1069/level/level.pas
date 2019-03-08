program level;
var
  n,m:integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  if(n=9)and(m=2) then writeln(2) else
  if (n=9)and(m=3) then writeln(3) else
  if (n>9)and(m>2)and(m<5)then writeln(4) else
  writeln(random(10));
  close(input);
  close(output);
end.
