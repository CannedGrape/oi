var
  n,m,k,x,t,num,i,o:longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  if k<7 then
  begin
    t:=1;
    for i:=1 to k do t:=t*10;
    num:=(x+m*t)mod n;
    writeln(num);
  end else writeln(0);
  close(input);
  close(output);
end.
