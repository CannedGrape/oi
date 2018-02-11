var n,m,k,x,lcm,c,s:int64; i:longint;
function gcd(a,b:int64):int64;
begin
 if b=0 then exit(a)
   else exit(gcd(b,a mod b));
end;
function ksm(xx:int64):int64;
var t:int64;
begin
  if xx=0 then exit(1);
  if xx=1 then exit(10);
  t:=ksm(xx div 2) mod c;
  ksm:=t*t mod c;
  if xx mod 2=1 then ksm:=ksm*10 mod c;
end;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  lcm:=n*m div gcd(n,m);
  c:=lcm div m;
  s:=ksm(k) mod c;
  x:=x+((s*m) mod n);
  if x>n-1 then x:=x-(n-1)-1;
  writeln(x);
  close(input); close(output);
end.
