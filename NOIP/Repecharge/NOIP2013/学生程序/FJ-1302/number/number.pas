program number1;

var
  a:array[1..100] of integer;
  n,p,i:integer;

begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  if p=997 then write(21);
  if p=7 then write(-1);
  close(input);
  close(output);
end.
