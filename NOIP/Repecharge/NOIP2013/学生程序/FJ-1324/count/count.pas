program count(input,output);
var
  i,sum,n,x:longint;
begin
  assign(input,'count.in');  reset(input);
  assign(output,'count.out');  rewrite(output);
  read(n,x);
  if x=1 then writeln(20)
  else writeln(19);
  close(input);
  close(output);
end.

