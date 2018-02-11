program ex01;
var sa:string;
    s:string;
    i,n,ans,k:longint;
    x:integer;


begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
read(n,x);
str(x,sa);


ans:=0;
for i:=1 to n do
   begin
   str(i,s);
   k:=pos(sa,s);

   while k<>0 do
      begin
        inc(ans);
        delete(s,k,1);
        k:=pos(sa,s);
      end;
   end;
write(ans);
close(input);
close(output);
end.


