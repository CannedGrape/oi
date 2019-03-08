program level;
var n,i,j,q,k:integer;a:array[1..1000]of integer;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(i,j);
  for q:=1 to j do
  begin
   read(a[j]);
   for k:=1 to a[j] do
   read(a[k]);
   readln;
  end;
  n:=j;
  writeln(j);
  close(input);
  close(output);
end.

