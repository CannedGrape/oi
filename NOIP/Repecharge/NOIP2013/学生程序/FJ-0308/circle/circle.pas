program circle;
  var n,m,k,x:longint;
      i:longint;
      re:longint;
      k1,k2:longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  read(n,m,k,x);
  i:=1;
  while  (round(Exp(i*ln(10))) mod n<>0)and
         (round(Exp(i*ln(10))) mod n<>1)and
         (i<=k)
    do inc(i);
  k1:=k div i;
  if round(Exp(i*ln(10))) mod n<>0 then while k1>n do k1:=k1 div n;
  k2:=k mod i;
  if (round(Exp(i*ln(10))) mod n)=1 then
    begin
      if k2=0 then re:=0 else
      re:=round(Exp(k2*ln(10))) mod n;
      x:=(x+k1+m*re) mod n;
    end
  else
    begin
      if k2=0 then re:=0 else
      re:=round(Exp(k2*ln(10))) mod n;
      x:=(x+m*re) mod n;
    end;
  write(x);
  close(input);
  close(output);
end.











