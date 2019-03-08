var
  n,m,i,t:longint; k,x:qword;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  t:=10 mod x;
  for i:=1 to k do
  begin
    x:=t*x;
    while x>=n do
    x:=x mod n;
  end;
  x:=x*m;
  while x>=n do
  x:=x mod n;
  x:=x+k+1;
  if x>=n then x:=x mod n;
  writeln(x);
  close(input);close(output);
end.
