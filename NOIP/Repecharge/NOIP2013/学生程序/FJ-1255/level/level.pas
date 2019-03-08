program level;
 var a:array[1..1000] of longint;
     i,j,t,n,m:longint;
 begin
   assign(input,'level.in');
   reset(input);
   assign(output,'level.out');
   rewrite(output);
   readln(n,m);
   write(m);
   close(input);
   close(output);
 end.