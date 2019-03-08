program count;
 var i,n,x,ans,j:longint;
     s:string;
     e:char;
 begin
   assign(input,'count.in');reset(input);
   assign(output,'count.out');rewrite(output);
   read(n);
   read(x);
   e:=chr(x+48);
   ans:=0;
   for i:=1 to n do
    begin
      str(i,s);
      j:=pos(e,s);
      while j<>0 do
       begin
         inc(ans);
         delete(s,1,j);
         j:=pos(e,s);
       end;
    end;
   write(ans);
   close(input);
   close(output);
 end.