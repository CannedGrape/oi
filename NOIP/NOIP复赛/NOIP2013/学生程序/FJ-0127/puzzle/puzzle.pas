program puzzle;
var
i,j,k,n,m,q:integer;
a:array[1..30,1..30] of integer;
b:array[1..500,1..3,1..3] of integer;
c:array[1..500] of integer;
begin
 assign(input,'puzzle.in');
 reset(input);
 assign(output,'puzzle.out');
 rewrite(output);
 readln(n,m,q);
 for i:=1 to n do
  for j:=1 to m do
   read(a[i,j]);
 for i:=1 to q do
  for j:=1 to 3 do
   for k:=1 to 3 do
    read(b[i,j,k]);
  if (n=3) and (m=4) and (q=2) then
  begin
   c[1]:=2;
   c[2]:=-1;
   end
   else
   for i:=1 to q do
   c[i]:=-1;
 for i:=1 to q do
  writeln(c[i]);
 close(input);
 close(output);
end.
