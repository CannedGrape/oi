var
  n,x,m,ans,l,k,p:longint;
begin
assign(input,'count.in');
assign(output,'count.out');
reset(input);
rewrite(output);
   readln(n,x);
  if x<>0 then
  begin
    m:=n;
    k:=1;
    p:=1;
    while m>0 do
      begin
      p:=p*10;
      l:=m mod 10;
      if l>x then
      begin
        inc(ans,(n div p+1)*k);
      end;
      if l=x then
      begin
        inc(ans,(n div p)*k);
        inc(ans,n mod k+1)
      end;
      if l<x then
      begin
        inc(ans,(n div p)*k);
      end;
      m:=m div 10;
      k:=k*10;
      end;
  end;
    if x=0 then
  begin
    m:=n;
    k:=1;
    p:=1;
    while m>=10 do
      begin
      p:=p*10;
      l:=m mod 10;
      if l>x then
      begin
        inc(ans,(n div p)*k);
      end;
      if l=x then
      begin
        inc(ans,(n div p-1)*k);
        inc(ans,n mod k+1)
      end;
      m:=m div 10;
      k:=k*10;
      end;
  end;
  writeln(ans);
close(input);
close(output);
end.