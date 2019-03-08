Program block;
var
   n:longint ;
   i,s,max,num :integer;
   a : array[1..50000] of word;
   b : array[1..10000 ,1..50000] of word;

   Begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
read(n);
for i:=1 to n do
begin read(a[i]);   end;

{for i:=1 to n do
begin if max<a[i] then max:=a[i]; end;}

for i:=1 to n do
    begin
    for s:=1 to a[i] do
    begin
    b[i,s]:=1;
    end;
    end;
for i:=1 to n do
    begin
    for s:=1 to a[i] do
    begin
    if b[i+1,s]=0 then num:=num+1;
    end;
    end;
write(num);
close(input);
close(output);

   End.
