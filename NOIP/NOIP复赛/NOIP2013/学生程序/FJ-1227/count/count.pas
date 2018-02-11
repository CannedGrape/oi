program exam1;
 var n,i,j,k,l,m,x:longint;
 begin
assign(input,'count.in');reset(input);
assign(output,'count.out');rewrite(output);
  m:=0;
  read(n,x);
  for i:=1 to n do
   begin
    j:=i;
    while j<>0 do
     begin
      if (j mod 10=x) then
       m:=m+1;
      j:=j div 10;
     end;
   end;
  write(m);
close(input);close(output);
 end.
