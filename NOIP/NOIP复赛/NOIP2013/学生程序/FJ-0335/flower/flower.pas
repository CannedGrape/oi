program flower;
var  h:array[1..1000000] of longint;
     i,j,k,m,n : longint;
begin
assign(input,'flower.in');reset(input);
assign(output,'flower.out');rewrite(output);
read(n);
for i:=1 to n do
read(h[i]);
for i:=1 to n-k do
 for j:=n-k downto 1 do
 begin
  if m=1 then if (h[2*i]>h[2*i-1]) and (h[2*i]>h[2*i+1]) and ( h[2*i-1]>h[2*i]) and (h[2*i]<h[2*i-1])  and
             (h[2*j]>h[2*j-1]) and (h[2*j]>h[2*j+1]) and ( h[2*j-1]>h[2*j]) and (h[2*j]<h[2*i-1])
  then k:=k;
  if m>1 then  if (h[2*i]>h[2*i-1]) and (h[2*i]>h[2*i+1]) and ( h[2*i-1]>h[2*i]) and (h[2*i]<h[2*i-1])  or
             (h[2*j]>h[2*j-1]) and (h[2*j]>h[2*j+1]) and ( h[2*j-1]>h[2*j]) and (h[2*j]<h[2*j-1])
  then k:=k;
 end;
writeln(n-k);
close(input);close(output);
end.
