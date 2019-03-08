program number;
var
a,b,te,fen:array[1..1000000] of longint;
x,y,p,q,i,j,n,t,max,k:longint;
begin
assign(input,'number.in');
reset(input);
assign(output,'number.out');
rewrite(output);
  readln(n,p);
  for x:=1 to n do read(a[x]);
te[1]:=a[1];
 for i:=2 to n do
   for j:=1 to i do
    te[i]:=te[i]+a[j];
fen[1]:=te[1];
 for y:=2 to n do
  for t:=1 to y-1 do
   begin
    max:=fen[t]+te[t];
     if (max>fen[y]) or (t=1) then
      fen[y]:=max;
   end;
 i:=0;
q:=fen[1];
 for i:=1 to n do
  if fen[i]>q then
  q:=fen[i];
if q<0 then
 begin
  k:=1;
  q:=abs(q);
 end;
y:=q mod p;
if k=1 then
write('-');
write(y);
close(input);
close(output);
end.



