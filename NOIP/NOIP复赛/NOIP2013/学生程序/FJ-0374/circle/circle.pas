var n,m,k,x,ans:longint;
 begin
  assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
  readln(n,m,k,x);
  m:=m*10;
  while m>=n do m:=m-n;
  ans:=x+m;
  while ans>n do ans:=ans-n;
  writeln(ans);
  close(input);
  close(output);
 end.
