program  count;
var
a: array[1..10000] of  longint;
    n:int64;
  x,i,j,k,m:integer;
  s:string;

begin
assign(input,'count.in'); reset(input);
assign(output,'count.out'); rewrite(output);
  read(n,x);
for i:=1 to n do
    str(a[i],s);
   length(s);
   for j:=1 to length(s) do
     a[j]:=m;
   if m='x' then  k:=k+1;
write(k);
close(input);
close(output);
end.



