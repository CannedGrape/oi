program count;
var n,i,j,x,y:longint;
begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 read(n,x);
 for i:=1 to n do
  begin
   if i=x then inc(j);
   if (i div 10=x)and(i>9) then inc(j);
   if (i div 100=x)and(i>99) then inc(j);
   if (i div 1000=x)and(i>999) then inc(j);
   if (i div 10000=x)and(i>9999) then inc(j);
   if (i div 100000=x)and(i>99999) then inc(j);
   if (i div 1000000=x)and(i>999999) then inc(j);
   if (i mod 10=x)and(i>9) then inc(j);
   if (i mod 100=x)and(i>99) then inc(j);
   if (i mod 1000=x)and(i>999) then inc(j);
   if (i mod 10000=x)and(i>9999) then inc(j);
   if (i mod 100000=x)and(i>99999) then inc(j);
   if (i mod 1000000=x)and(i>999999) then inc(j);
  end;
 writeln(j);
 close(input);close(output);
end.
