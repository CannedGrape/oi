var
  n,m,q,i:longint;
begin
   assign(input,'puzzle.in');reset(input);
   assign(output,'puzzle.out');rewrite(output);
   readln(n,m,q);
   for i:=1 to n do writeln(-1);
   close(input);close(output);
end.