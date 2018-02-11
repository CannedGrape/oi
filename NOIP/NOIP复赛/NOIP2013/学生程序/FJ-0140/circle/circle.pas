program circle;
var
  i,v,n,m,k,x:longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);i:=0;
  while i<k do
  begin
   m:=m*10;
  if m>=n then
  m:=m mod n;
  inc(i);
  end;
  if m+x>=n then
  writeln(m+x-n)
  else
  writeln(m+x);
  readln;
  close(input);close(output);
end.


