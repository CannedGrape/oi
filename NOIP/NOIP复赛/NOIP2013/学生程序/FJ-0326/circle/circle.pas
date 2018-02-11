var n,m,k,x,y:longint;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  if 10>n then y:=10 mod n
  else y:=n mod 10;
  writeln(y);
  if y=0 then writeln(x)
  else writeln(m+y+x);
  close(input);close(output);
end.
