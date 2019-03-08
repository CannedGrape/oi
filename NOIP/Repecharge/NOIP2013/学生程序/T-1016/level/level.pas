var
  a:array[1..15] of longint;
  i:longint;
begin
  assign(input,'level.in'); reset(input);
  assign(output,'level.out'); rewrite(output);
  for i:=1 to 15 do read(a[i]);
  if a[15]=0 then writeln(2) else writeln(3);
  close(input); close(output);
end.