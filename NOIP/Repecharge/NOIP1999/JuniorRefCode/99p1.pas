var
  n,k,m:longint;
  r:real;
begin
  write('n=');
  readln(n);
  r:=(sqrt(1+8.0*n)-1)/2;
  if abs(frac(r))<1e-5 then 
    k:=trunc(r)
  else
    k:=trunc(r)+1;
  m:=n-k*(k-1) div 2;
  if odd(k) then
    writeln(k+1-m,'/',m)
  else
    writeln(m,'/',k+1-m);
end.
