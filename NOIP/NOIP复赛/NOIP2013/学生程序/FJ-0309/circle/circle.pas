PROGRAM JK;
VAR n,m,k,p,i:longint;
  BEGIN
    assign(input,'circle.in');reset(input);
    assign(output,'circle.out');rewrite(output);
    read(n,m,k,p);
    p:=1;
    for i:=1 to k do
      p:=p*10;
    for i:=1 to p do
      k:=(k+m) mod n;
    write(k);
    close(input);close(output);
  end.
