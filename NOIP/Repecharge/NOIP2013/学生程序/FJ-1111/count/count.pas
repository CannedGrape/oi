Var
 i,a,ans,n,x:longint;
begin
 assign(input,'count.in');
 assign(output,'count.out');
 rewrite(output);
 reset(input);
 readln(n,x);
 for i:=1 to n do
 begin
  a:=i;
  if a mod 10=x then ans:=ans+1;
  a:=a-a mod 10;
  if a mod 100=x*10 then ans:=ans+1;
  a:=a-a mod 100;
  if a mod 1000=x*100 then ans:=ans+1;
  a:=a-a mod 1000;
  if a mod 10000=x*1000 then ans:=ans+1;
  a:=a-a mod 10000;
  if a mod 100000=x*10000 then ans:=ans+1;
 end;
 write(ans);
 close(input);
 close(output);
end.
