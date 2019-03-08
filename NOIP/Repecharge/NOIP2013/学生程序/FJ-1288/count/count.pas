var n,x,a,b,c,i,j,l,t:longint;
w,j1:array[1..1000000] of longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n,x);
  a:=n;
   w[1]:=n mod 10;
   n:=n div 10;
   for j:=1 to w[1] do
   if j=x then l:=l+1;
   b:=10;
  for i:=10 to a do
  begin
  t:=i;
   while (t>0) do
   begin
   w[i]:=t mod 10;
   if w[i]=x then l:=l+1;
   t:=t div 10;
   end;


   end;


  writeln(l);
  close(input);
  close(output);

end.
