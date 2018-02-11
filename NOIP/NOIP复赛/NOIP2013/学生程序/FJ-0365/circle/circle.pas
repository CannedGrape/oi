var i,n,m,k,x:int64; j:longint;
  begin  assign(input,'circle.in'); reset(input);
         assign(output,'circle.out'); rewrite(output);
   readln(n,m,k,x); i:=1;
    for j:=1 to k do
     i:=(i*10) mod n;  i:=(i*m) mod n;  i:=(i+x) mod  n;

     write(i); close(input); close(output);
     end.