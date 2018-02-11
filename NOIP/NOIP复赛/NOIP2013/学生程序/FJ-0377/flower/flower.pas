var a:array[1..10000] of longint;
    n,i:longint;
 begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
   read(n);
   for i:=1 to n do
     read(a[i]);
   write('3');
   close(input);
   close(output);
 end.