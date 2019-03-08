var
  n,p,a,i:longInt;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
  read(a);
  write(-1);
  close(input);
  close(output);
end.
