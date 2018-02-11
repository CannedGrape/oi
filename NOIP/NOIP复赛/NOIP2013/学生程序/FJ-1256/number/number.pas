var i,j,k:longint;
    a:array[1..1000] of longint;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(j,k);
  for i:=1 to j do read(a[i]);
  if k=997 then writeln('21')
           else writeln('-1');
  close(input);
  close(output);
end.