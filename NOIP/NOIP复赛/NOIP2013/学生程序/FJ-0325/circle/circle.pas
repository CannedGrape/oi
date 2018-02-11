var n,m,k,x,z,i:longint;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);  z:=m;
  m:=m mod n;
  for i:=1 to k do m:=m*10 mod n;
  m:=(m+x) mod n;
  writeln(m);
  close(input); close(output);
end.

