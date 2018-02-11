program circle;
uses math;
var n,m,x,p,q,j:longint;
    a,b,c:real;
    k:int64;
    i:integer;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n,m,k,x);
i:=1;
j:=n;
if (n mod 10)=0 then
begin
while j>10 do begin j:=j div 10; i:=i+1;end;
 p:=k mod i;
 if p=0 then writeln(x)
 else begin
 x:=p*10+x+m;
  if x>=n then x:=x mod n;
 writeln(x);end;
 end
else if k<7 then
  begin
   p:=(10**k) mod n;
   x:=p+x+m;
   if x>=n then x:=x mod n;
    writeln(x); {elsewriteln(6);}
  end;




{a:=ln(n)/ln(10);
b:=(k-a)-trunc(k-a);
c:=trunc(10**b)+1;
writeln(c+x);}



close(input);
close(output);
end.
