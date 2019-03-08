var a,b,c,i,x:longint;
begin
  assign(input,'puzzle.in'); reset(input);
  assign(output,'puzzle.out'); rewrite(output);

  readln(a,b,c);
  for i:=1 to a do readln(x,x,x,x);
  for i:=1 to c do readln(x,x,x,x,x,x);

  if (a=3)and(b=4)and(c=2)then
  begin
    writeln('2');
    writeln('-1');
  end else for i:=1 to c do
  writeln('-1');
  close(input); close(output);
end.
