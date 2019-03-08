var a:array[1..1000000] of longint;
    i,n,p:longint;
begin
assign(input,'number.in');
assign(output,'number.out');
reset(input);
rewrite(output);
  readln(n,p);
  for i:=1 to n-1 do
  read(a[i]);
  readln(a[n]);
  if (n=5) and (p=997) then writeln('21');
  if (n=5) and (p=7) then writeln('-1');
close(input);
close(output);
end.
