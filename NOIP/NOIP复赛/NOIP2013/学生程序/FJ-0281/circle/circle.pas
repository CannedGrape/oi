var
  l,t,n,m,k,x:longint;
begin
  assign(input,'circle.in');  reset(input);
  assign(output,'circle.out');  rewrite(output);
  readln(n,m,k,x);
  l:=k;  t:=m;
  while l<=k   do
    begin
      t:=t mod n;
      l:=l+1;
      t:=10*t;
    end;
  t:=t mod 10+x mod n;
  write(t);
  close(input);  close(output);
end.

