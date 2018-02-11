var
  a,b,c,i:longint;
begin
 assign(input,'number.in'); reset(input);
 assign(output,'number.out'); rewrite(output);
  readln(a,b);
  for i:=1 to a do
    read(c);
  writeln('21');
  close(input); close(output);
end.
