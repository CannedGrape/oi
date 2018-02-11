var a,b,c:array[1..1000000]of longint;
    p,i,j,k,l,m,n,max,m1,fu:longint;
begin
   assign(input,'number.in');reset(input);
   assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];
  c[1]:=a[1];
  if c[1]+b[1]>c[1] then m1:=c[1]+b[1]
  else m1:=c[1];
  max:=a[1];
  fu:=0;
  for i:=2 to n do
   begin
    if a[i]>0 then
     begin
      b[i]:=max+a[i];
      max:=max+a[i];
     end
    else
      b[i]:=max;
    c[i]:=m1;
    if (b[i]+c[i]>m1)and(i<>n) then m1:=c[i]+b[i];
   end;
  k:=abs(m1);
  k:=k mod p;
  if m1<0 then write('-',k)
  else writeln(k);
   close(input);close(output);
end.
