var ans,n,k,x,l,m:int64;
    i:longint;
 begin
assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
  read(n,m,k,x);
  l:=1;
  for i:=1 to k do
  l:=(l*10) mod n;
  ans:=(x+m*l)mod n;
  write(ans);
close(input);
close(output);
 end.
