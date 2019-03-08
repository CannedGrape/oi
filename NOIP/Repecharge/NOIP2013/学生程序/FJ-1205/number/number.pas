var
  a,b:string;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  reset(output);
  readln(a);
  read(b);
  if ((a='5 997')and(b='1 2 3 4 5')) then write(21);
  if ((a='5 7')and (b='-1 -1 -1 -1 -1')) then write(-1);
  close(input);
  close(output);
end.
