program circle;
var
  n,m,k,x,t,x1,t2:longint;
  t1,t3:qword;
  s1,s2,s3:string;
begin
  assign(input,'circle.in');
  reset(input);
  read(n);read(m);read(k);read(x);
  x1:=x;t2:=0;
  repeat
    x:=x+m;
    x:=x mod n;
    t2:=t2+1;
  until(x=x1);
  t1:=round(exp(k*ln(10)));
  t3:=t1 mod t2;
  assign(output,'circle.out');
  rewrite(output);
  writeln((x+(k*t3))mod n);
  close(input);close(output);
end.
