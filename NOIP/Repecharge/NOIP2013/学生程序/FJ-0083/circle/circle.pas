program circle;
const filename='circle';
var n,m,k,x:longint;
temp,ans:int64;

function power(a,b:longint):int64;
var t,ans:int64;
begin
  if b=0 then exit(1);
  if b=1 then exit(a);
  t:=power(a,b shr 1);
  ans:=(t*t)mod n;
  if odd(b) then
    ans:=(ans*a)mod n;
  exit(ans);
end;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  read(n,m,k,x);

  temp:=(power(10,k))mod n;
  ans:=(temp*int64(m)+int64(x))mod n;

  write(ans);

  close(input);close(output);
end.
