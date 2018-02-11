program circle;
var
  s,t,j,n,m,k,x,i:longint;

begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);

   read(n,m,k,x);
   s:=1;
   for j:=1 to k do
   s:=s*10;
   for i:=1 to s do
   begin
   t:=x+m;
   if t>=n then
   t:=t-n;
   x:=t;
   end;
   write(t);
   close(input);close(output);

end.
