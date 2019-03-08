var
 a,b,i,m,n,x,jilu:longint;
begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
 readln(n,x);
 for i:=1 to n do
 begin
  a:=i;
  while a<>0 do
  begin
  b:=a;
  if b mod 10=x then jilu:=jilu+1;
  a:=a div 10;
  end;
 end;
 writeln(jilu);
 close(input);close(output);
end.
