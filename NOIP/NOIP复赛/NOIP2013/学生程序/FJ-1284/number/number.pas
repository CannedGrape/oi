program number;
var a,b,c:array [1..350000] of longint;
    i,j,n,p,max,h,k:longint;
 begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
   b[i]:=a[i];
   h:=0;
   for j:=1 to i do
   begin
    h:=0;
    for k:=j to i do
    begin
     h:=h+a[k];
     if h>b[i] then b[i]:=h;
    end;
   end;
  end;
  c[1]:=b[1];
  for i:=2 to n do
  begin
   c[i]:=c[1]+b[1];
   for j:=1 to i-1 do
   if c[j]+b[j]>c[i] then c[i]:=c[j]+b[j];
  end;
  max:=c[1];
  for i:=1 to n do
  if max<c[i] then max:=c[i];
  if max<0 then write('-');
  max:=abs(max);
  write(max mod p);
  close(input);close(output);
 end.



