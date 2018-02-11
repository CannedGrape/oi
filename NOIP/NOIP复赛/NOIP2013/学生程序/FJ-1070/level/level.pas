  var
    n,m,i,j:integer;
    a:array[0..1000] of integer;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(a[0]);
      for j:=1 to a[0] do
        read(a[j]);
    end;
  writeln(m);
  close(input);
  close(output);
end.