program sddd;
var n,x,ans,b:longint;
procedure qq(a:longint);
begin
   if a>9 then
   begin
      if x=a mod 10 then ans:=ans+1;
      qq(a div 10);
   end
   else if a=x then ans:=ans+1;
end;
begin
   assign(input,'count.in');reset(input);
   assign(output,'count.out');rewrite(output);
   read(n);
   readln(x);
   for b:=1 to n do qq(b);
   write(ans);
   close(input);
   close(output);
end.