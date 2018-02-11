var
   a,b,c,d,e,f,g,h,i,s:integer;
begin
   assign(input,'match.in');
   reset(input);
   assign(output,'match.out');
   rewrite(output);
   readln(a);
   readln(b,c,d,e);
   readln(f,g,h,i);
   s:=f-b;
  if s=0 then s:=s+2;
   close(input);
   writeln(s);
   close(output);
end.
