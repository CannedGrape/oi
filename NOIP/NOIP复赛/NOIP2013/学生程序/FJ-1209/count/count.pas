var
  x,n,i,j,count:longint;
begin
  assign(input'count.in');
  reset(input);
  assign(output'count.out');
  rewrite(output);
  read(n,x);
  count:=0;
  for i:=1 to n do
begin
  j:=i;
  repeat
  if (j mod 10)=x then inc(count);
  j:=j div 10;
  until j=0;
end;
  write(count);
  close(input);
  close(output);
end.


