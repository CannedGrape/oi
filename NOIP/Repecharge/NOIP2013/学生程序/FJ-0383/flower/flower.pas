Program flower;
var
   n:longint ;
   i,s,max,num :integer;
   a : array[1..50000] of word;
   b : array[1..10000 ,1..50000] of word;

   Begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
read(n);
for i:=1 to n do
read(a[i]);
{for i:=1 to n do
begin if max<a[i] then max:=a[i]; end;}
for i:=2 to n+1 do
for s:=1 to a[i] do
b[i,s]:=1;
for i:=2 to n+1 do
    for s:=1 to a[i] do
    if (b[i+1,s]=0) and (b[i-1,s]=0)  then num:=num+1;
    if (a[1]<a[2])  then num:=num*2+1;
    if (a[1]>a[2])  then num:=num*2-1;
    write(num);
close(input);
close(output);

   End.

