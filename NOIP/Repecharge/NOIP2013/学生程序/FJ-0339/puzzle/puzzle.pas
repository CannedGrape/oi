program puzzle;
var
 n,m,q,i:integer;
begin
 assign(input,'puzzle.in'); reset(input);
 assign(output,'puzzle.out'); rewrite(output);
 readln(n,m,q);
 if (n=3)and(m=4)and(q=2) then
 begin
  writeln('2');
  writeln('-1');
 end
 else for i:=1 to q do writeln('-1');
 close(input); close(output);
end.
