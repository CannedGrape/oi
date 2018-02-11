program e1;
var a,b,c,d,e,f,n,i,x,k:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  read(n,x);
  for i:=1 to n do
  begin
    a:=i mod 10;
    b:=(i mod 100) div 10;
    c:=(i mod 1000) div 100;
    d:=(i mod 10000) div 1000;
    e:=(i mod 100000) div 10000;
    f:=(i mod 1000000) div 100000;
    if a=x then inc(k);
    if b=x then inc(k);
    if c=x then inc(k);
    if d=x then inc(k);
    if e=x then inc(K);
    if f=x then inc(k);
  end;
  write(k);
  close(input);close(output);
end.

