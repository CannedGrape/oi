program count;
 var n,x,j:int64;
     i:integer;
  begin
   assign(input,'count.in');
   reset(input);
   assign(output,'count.out');
   rewrite(output);
   readln(n,x);
   for i:=n downto 1 do
   j:=(ord(x));
   writeln(j*4);
   close(input);
   close(output);
  end.