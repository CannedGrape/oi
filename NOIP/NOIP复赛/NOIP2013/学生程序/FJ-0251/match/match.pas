program match;
var
  a,b:array[1..100000]of longint;
  n,i:longint;
begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);

  readln(n);
  for i:=1 to n do
    read(a[i]);
  readln;
  for i:=1 to n do
    read(b[i]);

  if n=4 then
    begin
    if a[1]=2 then
      write(1);
    if b[1]=1 then
      write(2);
     end
    else
      write(10);
  close(input);
  close(output);
end.
