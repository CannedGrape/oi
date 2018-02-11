var n,m,k,x,kk,t,p:int64;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  kk:=k; t:=1; p:=10;
  while kk>0 do
   begin
    if odd(kk) then t:=((t mod n)*(p mod n)) mod n;
    p:=((p mod n)*(p mod n)) mod n;
    kk:=kk shr 1;
   end;
  t:=((t mod n)*(m mod n)) mod n;
  x:=((x mod n)+t) mod n;
  writeln(x);
  close(input); close(output);
end.
