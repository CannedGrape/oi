var
   i:longint;
   n,m,j,t,tot,k,x,y:int64;
function ksm(x,y:int64):int64;
var
   k:longint;
begin
   if y=1 then exit(x);
   if y=0 then exit(1);
   k:=ksm(x,y div 2);
   if y mod 2=1 then ksm:=k*k*x else ksm:=k*k;
end;
function gcd(x,y:longint):longint;
begin
   if x<y then exit(gcd(y,x));
   if x mod y=0 then exit(y);
   exit(gcd(y,x mod y));
end;
function ef(l,r:int64):longint;
var
   mid:int64;
begin
   while l<r  do
   begin
     mid:=(l+r)div 2;
     if ksm(10,mid)>j then r:=mid else l:=mid;
     if l+1=r then break;
   end;
   if ksm(10,l)>=j then exit(l) else exit(r);
end;
begin
   assign(input,'circle.in');reset(input);
   assign(output,'circle.out');rewrite(output);
   readln(n,m,k,x);
   j:=gcd(n,m);
   j:=n*m div j;
   y:=ef(0,k);
   tot:=ksm(10,y);
   k:=k-y;
   t:=tot mod j;
   while k>0 do
   begin
     t:=t*10 mod m;
     k:=k-1;
   end;
   x:=x+t-1;
   if x>n-1 then x:=x-n;
   writeln(x);
   readln;
   close(input);close(output);
end.
