program circle;
var
n,m,k,x,tmp,i:longint;
s:int64;
//f1,f2:text;
begin
//assign(f1,'circle.in');reset(f1);
//assign(f2,'circlel.out');rewrite(f2);
readln(n,m,k,x);
tmp:=x-1;
s:=1;
for i:=1 to k do s :=s*10;
if m=n then tmp:=tmp
else
for i:=1 to s do tmp:=(tmp+m) mod n;
writeln(tmp);
//close(f1);close(f2);
end.
