program count;
 var n,i,h,j:longint;
           x:integer;
           k,g:ansistring;
  begin
   assign(input,'count.in');reset(input);
   assign(output,'count.out');rewrite(output);
   read(n,x);
   str(x,k);
   for i:=1 to n do
     begin
      str(i,g);
      for j:=1 to length(g) do
         if g[j]=k then h:=h+1;
     end;
    write(h);
    close(input);close(output);
   end.
