var i,k,m,n,x,tt,ans:longint;
function gcd(a,b:longint):longint;
begin 
 if b=0 then exit(a);
 exit(gcd(b,a mod b));
end;
function ksm(x:longint):int64;
var t:longint;
begin 
 if x=0 then exit(1);
 if x=1 then exit(10);
 t:=ksm(x div 2);
 t:=t*t mod tt;
 if x mod 2=1 then t:=t*10 mod tt;
 exit(t);
end;
begin 
 assign(input,'circle.in');reset(input);
 assign(output,'circle.out');rewrite(output);
 readln(n,m,k,x);
 tt:=n div gcd(n,m);
 ans:=ksm(k);
 x:=x+m*ans mod n;
 writeln(x);
 close(input);close(output);
end.