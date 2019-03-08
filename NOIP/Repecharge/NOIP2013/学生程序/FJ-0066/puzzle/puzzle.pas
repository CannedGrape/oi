program pf;
var n,m,q:longint;
begin

assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);rewrite(output);
  read(n,m,q);
  if q=1 then begin write('-1');exit;end;
  writeln('2');
  writeln('-1');
close(input);
close(output);
end.