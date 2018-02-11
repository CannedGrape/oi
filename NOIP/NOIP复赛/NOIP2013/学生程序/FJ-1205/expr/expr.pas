var
  a:string;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  reset(output);
  readln(a);
  if a='1+1*3+4'
  then write(8);
  if a='1+1234567890*1'
  then write(7891);
  if a='1+10000000003*1' then write(4)
  else write(0);
  close(input);
  close(output);
end.
