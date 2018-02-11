var i,j,k,n,m,x,t:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n,x);
  for i:=1 to n do
   begin
    t:=i;
    if t div 1000000=x then inc(k);
    t:=t mod 1000000;
    if t div 100000=x then inc(k);
    t:=t mod 100000;
    if t div 10000=x then inc(k);
    t:=t mod 10000;
    if t div 1000=x then inc(k);
    t:=t mod 1000;
    if t div 100=x then inc(k);
    t:=t mod 100;
    if t div 10=x then inc(k);
    t:=t mod 10;
    if t=x then inc(k);
   end;
  write(k);
  close(input);
  close(output);
  end.