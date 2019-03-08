var n,x,i,ans,s:longint;
begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 read(n);
 read(x);
 ans:=0;
 for i:=1 to n do
  begin
  s:=i;
  while s>0 do
   begin
    if (s mod 10=x) then inc(ans);
    s:=s div 10;
   end;
  end;
  write(ans);
 close(input);close(output);
end.