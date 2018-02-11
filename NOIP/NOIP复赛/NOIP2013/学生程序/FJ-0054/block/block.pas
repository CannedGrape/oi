var
   ans,x,y:int64;
   n,m,i,j:longint;
begin
   assign(input,'block.in');reset(input);
   assign(output,'block.out');rewrite(output);
   readln(n);
   for i:=1 to n do
     begin
       read(x);
       if x>y then ans:=ans+x-y;
       y:=x;
     end;
   writeln(ans);
   close(input);close(output);
end.

