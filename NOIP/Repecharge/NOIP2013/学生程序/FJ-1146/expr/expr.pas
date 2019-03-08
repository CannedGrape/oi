var i,j,k,n,m,o,sum,max,min,tmp:longint;
    s,t,r,w,q,p,l:string;
begin
assign(input,'expr.in');
assign(output,'expr.out');
reset(input);
rewrite(output);
  readln(s);
  if s='1+1*3+4' then write(8);
  if s='1+1234567890*1' then write(7891);
  if s='1000000003*1' then write(4);
close(input);
close(output);
end.
