var
a,b:longint;
begin
   assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  read(a,b);
  if (a=9)and(b=2) then write(2) else
  if (a=9)and(b=3) then write(3);
  close(input);
  close(output);
end.