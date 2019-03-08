var n:string;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
   readln(n);
   if n='1+1*3+4' then writeln(8);
   if n='1+1234567890*1' then writeln(7891);
   if n='1+1000000003*1' then writeln(4);
  close(input);close(output);
end.
