var a,b,c:array[0..1000001] of longint;
    n,p,i,max,ans:longint;
begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 read(n);
 read(p);
 for i:=1 to n do read(a[i]);
 b[1]:=a[1];
 c[1]:=b[1];
 for i:=2 to n do
  begin
   b[i]:=b[i-1]+a[i];
   c[i]:=c[i-1]+b[i-1];
  end;
  max:=c[1];
  for i:=2 to n do
   if c[i]>max then max:=c[i];
   ans:=max mod p;
   write(ans);
 close(input);close(output);
end.