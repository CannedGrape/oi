var
  a,b,f1,f2:array[0..100001]of longint;
  n,m,i,j,l1,l2,t,s,r,x,y,l:longint;


begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  i:=1;s:=1;
  repeat
    j:=i;
    if a[i]>a[i+1] then
      while (i<=n)and(a[i]>a[i+1]) do inc(i)
    else if a[i]<a[i+1] then
           while (i<=n)and(a[i]<a[i+1]) do inc(i)
         else while (i<=n)and(a[i]=a[i+1]) do inc(i);
    s:=s+1;
    if a[i]=a[i-1] then dec(s);
  until i>=n;
  writeln(s);
  close(input);close(output);
end.


