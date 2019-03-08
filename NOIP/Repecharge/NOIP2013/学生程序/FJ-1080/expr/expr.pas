program expr;
 var k:array[1..1000] of int64;
     i,n:longint;
     j:integer;
  begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
   readln(i,j);
   inc(j);
   if (ord(k[j])>48) and (ord(k[j])<=59) then
   i:=k[j];
   for n:=1 to i do
   write(i,' ');
   close(input);
   close(output);
  end.
