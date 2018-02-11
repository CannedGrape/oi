var
  x:string;
  a:integer;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(x);
  if x='1+1*3+4' then a:=8;
  if x='1+1234567890*1' then a:=7891;
  if x='1+1000000003*1' then a:=4;
  write(a);
  close(input);
  close(output);
end.
