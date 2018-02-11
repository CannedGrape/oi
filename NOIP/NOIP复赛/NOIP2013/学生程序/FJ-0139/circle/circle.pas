var a,b:array[1..1000] of longint;
i,j,l,m,n,o,p,q,s,t,x,y:int64; k,r:int64;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
readln(o,m,k,x); n:=0;
repeat
n:=n+o;
p:=n mod m;
until (p=0);
r:=1;i:=0;
repeat
r:=r*10;
r:=r mod n;
i:=i+1;
until (i=k-1);
r:=r*10+x;
r:=r mod n;
r:=r mod o;
write(r);
close(input);close(output);
end.
