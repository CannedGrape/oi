var n,m,k,x:longint;
    a,b,ans:int64;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  ans:=1;a:=10;b:=k;
  while b<>0 do
  begin
    if b mod 2=1 then ans:=(ans*a) mod n;
    b:=b div 2;
    a:=(a*a) mod n;
  end;
  ans:=(ans*m) mod n;
  x:=(x+ans) mod n;
  writeln(x);
  close(input);close(output);
end.
