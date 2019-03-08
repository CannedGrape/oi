var n,m,x,a,b:longint;
    k:int64;

   begin
    assign(input,'circle.in');reset(input);
    assign(output,'circle.out');rewrite(output);

    read(n);read(m);read(k);read(x);


    a:=(10*m) mod n;

    b:=a+x;

    if b>n then b:=b mod n;
    write(b);  close(input);close(output);
   end.
