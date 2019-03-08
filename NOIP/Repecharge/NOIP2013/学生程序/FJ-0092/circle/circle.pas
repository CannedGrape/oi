var x,k,m,n,l,a,b,t:int64;
i:longint;
count,j:int64;
function gcd(a,b:longint):longint;
begin
 if a mod b=0 then gcd:=b else gcd:=gcd(b,a mod b);
      end;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n,m,k,x);
if k<7 then begin
j:=10;
for i:=1 to k do
j:=10*j;
for i:=1 to j do
  begin
  x:=x+m;
  if x>n then x:=x-n;
  end;
writeln(x);  close(input); close(output);  exit;end;

   if gcd(n,m)=m then t:=m else t:=n;
   j:=10;
   for i:=1 to k do
      j:=j*10 mod t;
      count:=j mod t;
for i:=1 to count do
  begin
  x:=x+m;
  if x>n then x:=x-(n+1);
  end;
writeln(x);

close(input);
close(output);

end.


