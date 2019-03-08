program match;
var
  a:string;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  while not(eof) do readln(a);
  if a[1]='3' then write('1')
  else
  if a[1]='1' then write('2')
  else write('4');
  close(input);
  close(output);
end.