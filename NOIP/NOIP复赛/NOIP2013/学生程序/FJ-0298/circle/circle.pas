var n,m,k,x,ans,t,y,t1,t2,yu:int64;

begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  t1:=n;t2:=m;
  if t1 mod t2=0 then t:=t1
    else
      begin
        repeat
         t1:=t1+n;
         yu:=t1 mod t2;
        until yu=0;
      end;
  t1:=t1 div m;
  t:=1;y:=10;
  while k<>0 do
  begin
    if k and 1=1 then t:=t*y mod t1;
    y:=y*y mod t1;
    k:=k shr 1;
  end;
  ans:=(x+t*m) mod n;
  writeln(ans);
  close(input);close(output);
end.
