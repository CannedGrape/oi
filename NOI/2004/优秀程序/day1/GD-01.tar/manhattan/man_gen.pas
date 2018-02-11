const
  m=10;
  n=10;
  k=10;
var
  i,j:longint;
begin
  assign(output,'manhattan.in'); rewrite(output);
  randomize;
  writeln(m,' ',n);
  for i:=1 to m do
    if random(2)=1 then write('E') else write('W');
  writeln;
  for i:=1 to n do
    if random(2)=1 then write('S') else write('S');
  writeln;
  for i:=1 to m do
    write(random(10000),' ');
  writeln;
  for i:=1 to n do
    write(random(10000),' ');
  writeln;
  writeln(k);
  for i:=1 to k do
    writeln(random(m)+1,' ',random(n)+1,' ',random(m)+1,' ',random(n)+1);
  close(output);
end.

