program level;
var
  n,m,i,j,k:integer;
  b:array[0..1005] of integer;
  a:array[0..1005,0..1005] of integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);writeln(m);
  for i:=1 to 5 do readln(b[i]);
  for i:=2 to m do begin
  for j:=1 to 4 do read(a[j,i]);
  readln;end;
  close(input);
  close(output);
end.
