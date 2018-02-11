var
  a:array[1..100000]of longint;
  n,i,j,k,ans,s:longint;

begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=n;
  k:=1;
  for i:=2 to n-1 do
    if ((a[i]>=a[i-1]) and (a[i]<=a[i+1]))
    or ((a[i]<=a[i-1]) and (a[i]>=a[i+1])) then dec(ans)
    else k:=i;
  if a[n]=a[k] then dec(ans);
  writeln(ans);
  close(input);
  close(output);
end.
