program circle;
var m,n,k,x,i,j,t:longint;
    l:qword;
begin
 assign(input,'circle.in'); reset(input);
 assign(output,'circle.out'); rewrite(output);
 readln(n,m,k,x);
 l:=1;
 t:=1;
 if k>=10000000 then
  begin
   for i:=100 to (k div 2) do
    if (k mod i)=0 then
     begin
      for j:=1 to i do
       t:=(t*10) mod n;
      for j:=1 to (k div i) do
       l:=(l*t) mod n;
      break;
     end;
   end
 else
  for i:=1 to k do
   l:=l*10 mod n;
 l:=(l*m) mod n;
 x:=(x+l) mod n;
 writeln(x);
 close(input); close(output);
end.
