program prodstool;
uses
  prectlib;
var
  n : integer;
begin
  n := gridsize;
  writeln ('gridsize = ', n);
  writeln ('rect(3, 6, 3, 8) = ', rect(3, 6, 3, 8));
  writeln ('rect(1, 5, 1, 3) = ', rect(1, 5, 1, 3));
  report (4, 3, 4, 8, 4, 4, 9, 4);
end.
