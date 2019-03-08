program count;
var n,x,i,total,s:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out');rewrite(output);
  readln(n,x);total:=0;
  for i:=1 to n do
  begin
   s:=i;
   while s<>0 do
    begin
     if s mod 10=x then inc(total);
     s:=s div 10
   end;
  end;
  write(total);
  close(input);
  close(output);
end.

