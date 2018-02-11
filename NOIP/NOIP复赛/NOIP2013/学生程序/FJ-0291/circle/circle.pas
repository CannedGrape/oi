var x,k,n,m,ans,p:int64;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  ans:=m; p:=10;
  while k<>0 do
  begin
    if k and 1=1 then ans:=(ans*p) mod n;
    p:=(p*p) mod n;
    k:=k shr 1;
  end;
  ans:=(ans+x) mod n;
  writeln(ans);
  close(input); close(output);
end.
