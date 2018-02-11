Program HJF_count;
var
   n,i,j,ans:longint;
   s:string;
   x:char;

begin
   ans:=0;
   assign(input,'count.in');   reset(input);
   assign(output,'count.out');   rewrite(output);
   readln(n,x,x);
   for i:=1 to n do
   begin
      str(i,s);
      for j:=1 to length(s) do
         if s[j]=x then inc(ans);
   end;
   writeln(ans);
   close(input);
   close(output);
end.
