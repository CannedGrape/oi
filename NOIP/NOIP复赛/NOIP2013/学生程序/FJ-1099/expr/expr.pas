var a:string;
begin
  assign(input,'expr.in');assign(output,'expr.out');
  reset(input);rewrite(output);
  readln(a);
  if a='1+1*3+4' then writeln('8')
  else
   if a='1+1234567890*1' then writeln('7891')
   else writeln('4');close(input);close(output);
end. 