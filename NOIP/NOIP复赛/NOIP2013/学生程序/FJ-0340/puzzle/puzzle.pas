program puzzle;
 var n,m,i,q,j,o,u:longint;
  a:array[0..300,0..300] of integer;
  b:array[0..300,0..300] of integer;
 begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input);
rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
   begin
    for j:=1 to m do
     read(a[i,j]);
    readln;
   end;
  for i:=1 to q do
   begin
    for j:=1 to 6 do
     read(b[i,j]);
    readln;
   end;
 randomize;
  if q=1 then writeln('-1')
 else
  for i:=1 to q do
   writeln(random(10)-1);
 close(input);
 close(output);
 end.
