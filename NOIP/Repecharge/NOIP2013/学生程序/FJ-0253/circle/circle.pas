program circle;
var
  n,m,k,x,p1,p2,h,z,i,j:longint;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  h:=k;
  p1:=k mod 1000;
  k:=k div 1000;
  p2:=k mod 1000;
  k:=k div 1000;
  for i:=1 to 10 do
    x:=(x+p1*m) mod n;
  if h>1000 then
  for i:=1 to 10 do
    for j:=1 to 1000 do
      x:=(x+p2*m) mod n;
  if h>1000000 then
  for i:=1 to 10 do
    for j:=1 to 1000 do
      for z:=1 to 1000 do
        x:=(x+k*m) mod n;
  writeln(x);
  close(input);
  close(output);
end.
