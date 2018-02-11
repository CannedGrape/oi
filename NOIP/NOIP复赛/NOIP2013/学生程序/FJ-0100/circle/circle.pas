var
  n,m,k,x,t,v:integer;i,j:longint;
  a:array[0..1000000]of longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);t:=-1;
  for i:=0 to n-1 do
  a[i]:=i;
  v:=0;
  repeat
  inc(v);
   for j:=0 to n-1 do
   begin
     t:=j;
     a[t]:=m+a[t];
     if a[t]=n then a[t]:=0;
     if a[t]>n then a[t]:=a[t] mod n;
   end;
 until v=10;
 write(a[x]);
 close(input);close(output);
end.


