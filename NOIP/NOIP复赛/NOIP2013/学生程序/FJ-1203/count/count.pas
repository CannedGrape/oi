var
  a,b,c,i:longint;
procedure pd(y,z:longint);
begin
  repeat
    if y mod 10=z then inc(c);
    y:=y div 10;
  until y=0;
end;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(a,b);
  for i:=1 to a do pd(i,b);
  writeln(c);
  close(input);
  close(output);
end.
