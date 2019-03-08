var i,j,k,l,m,n,x,y,t:longint;
 begin
  assign(input,'count.in');
  assign(output,'count.out');
   reset(input);
   rewrite(output);
    read(n,x); t:=0;
    for i:=1 to n do
     begin
      j:=i;
      while j>0 do
       begin
        if j mod 10=x then inc(t);
        j:=j div 10;
       end;
      end;
      write(t);
   close(input);
   close(output);
 end.
