program circle;
 var n,m,k,x,i:integer;
  assign(input,circle);
  reset('circle.in');
  assign(output,circle);
  rewrite('circle.out');
begin
  read(n);read(m);read(k);read(x);
  close('circle.in');
  for i:=1 to 10^k do
    x:=x+m;
    writeln(x);
    close('circle.out');
end.
