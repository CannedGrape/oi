Var
 n,p,i,j,max:longword;
 a,b:array[1..1000000]of longword;
begin
 assign(input,'number.in');
 assign(output,'number.out');
 reset(input);
 rewrite(output);
 readln(n,p);
 for i:=1 to n do
  read(a[i]);
 for i:=2 to n do
  if a[i]>0 then a[i]:=a[i-1]+a[i];
 b[1]:=a[1];
 for i:=2 to n do
 begin
  max:=(a[1]+b[1])mod p;
  for j:=2 to(i-1)do
   if a[j]+b[j]>max then max:=(a[j]+b[j])mod p;
  b[i]:=max;
 end;
 max:=b[1];
 for i:=2 to n do
  if b[i]>max then max:=b[i];
 write(max);
 close(input);
 close(output);
end.
