//circle
var i,j,n,m,k,x:longint;
function fm(x:longint):longint;
var t:longint;q:int64;
begin
  if x=0 then exit(1);
  if x=1 then exit(10 mod (n));
  t:=x div 2;
  q:=fm(t);
  q:=(int64(q*q) mod (n));
  if odd(x) then
  begin
    q:=(int64(q*10) mod (n));
  end;
  exit(q mod (n));
end;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  writeln(((int64(fm(k)*m+x) mod n)) mod n);
  close(input);close(output);
end.
