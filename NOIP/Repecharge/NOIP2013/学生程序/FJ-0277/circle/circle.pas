var n,m,k,x,i,p:longint;
    ans,t,a:qword;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  p:=(k+1) div 12+1;
  a:=(k+1) mod 12;
  t:=1;
  for i:=1 to a do t:=t*10;
  for i:=1 to p do
   begin
     t:=t mod n;
     t:=t*100000000000;
   end;
  t:=t mod n;
  ans:=((t*m mod n)+x) mod n;
  writeln(ans);
  close(input);close(output);
end.

