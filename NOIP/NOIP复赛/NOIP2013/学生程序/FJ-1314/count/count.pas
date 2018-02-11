program count;
var
  n,x,i,j,k:integer;
  a:array[1..999] of integer;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n);
  read(x);
  j:=0;
  for i:=1 to n do
    a[i]:=i;
  for i:=1 to n do
  begin
    k:=a[i] div 100;
    if k=x then inc(j);
    k:=a[i] mod 100 div 10;
    if k=x then inc(j);
    k:=a[i] mod 10;
    if k=x then inc(j);
  end;
  write(j);
  close(input);
  close(output);
end.
