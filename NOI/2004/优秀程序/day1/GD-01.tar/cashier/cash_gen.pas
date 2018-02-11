const
  n=1000;
var
  i,j,tot:longint;
begin
  assign(output,'cashier.in'); rewrite(output);
  randomize;
  writeln(n,' ',random(100));
  tot:=0;
  for i:=1 to n do
  begin
    repeat
      j:=random(4);
    until (j<>1)and(j<>2)or((j=1)or(j=2))and(tot<100);
    case j of
      0:writeln('I ',random(1000));
      1:writeln('A ',random(100));
      2:writeln('S ',random(100));
      3:writeln('F ',random(100)+1);
    end;
    if (j=1)or(j=2) then inc(tot);
  end;
  close(output);
end.

ut);
end.

.



d.

.



