program count;
 var
 n,x,a,i:longint;
 begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 readln(n,x);
 for i:=1 to n do
  begin
   if (i mod 10) div 1=x then inc(a);
   if (i mod 100) div 10=x then inc(a);
   if (i mod 1000) div 100=x then inc(a);
   if (i mod 10000) div 1000=x then inc(a);
   if (i mod 100000) div 10000=x then inc(a);
   if (i mod 1000000) div 100000=x then inc(a);
   if (i mod 10000000) div 1000000=x then inc(a);
  end;
 write(a);
 close(input);close(output);
 end.