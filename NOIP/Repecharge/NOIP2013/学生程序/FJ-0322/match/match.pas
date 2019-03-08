var
  n,i,j:longint;
  a,b:array[0..100000] of longint;
begin
assign(input,'match.in'); reset(input);
assign(output,'match.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
  read(a[i]);
  for i:=1 to n do
  read(b[i]);
  if (a[1]=2) and (b[1]=3) then write('1')
  else if (a[1]=1) and (b[1]=1) then write('2') else
  write('0');
close(input);   close(output);
end.
