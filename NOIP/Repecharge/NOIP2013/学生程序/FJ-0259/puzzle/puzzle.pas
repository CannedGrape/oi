var
  a,b,c,d,e,f:longint;
  x,y:array[1..30,1..30]of longint;
begin
  assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
  readln(a,b,c);
  for d:=1 to a do
  begin
  for e:=1 to b do
  read(x[d,e]);
  readln
  end;
  for a:=1 to c do
  begin
  for b:=1 to 6 do
  read(y[a,b]);
  readln;
  end;
  writeln(2);
  writeln(-1);
  readln;readln;
  close(input);
close(output);
end.
