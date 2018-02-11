var n,m,k,x,y,ans,a:int64;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  a:=10;
  y:=1;
  while k<>0 do
    begin
      if k and 1=1 then y:=(y*a) mod n;
      k:=k shr 2;
      a:=(a*a) mod n;
    end;
  m:=m mod n;
  ans:=((x mod n)+(m*y) mod n) mod n;
  writeln(ans);
  close(input);close(output);
end.