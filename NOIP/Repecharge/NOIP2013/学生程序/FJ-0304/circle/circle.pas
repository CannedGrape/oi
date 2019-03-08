program ex;
var a:array[0..1000000]of longint;
i,j,k,l,n,m,x,t:longint;
begin
assign(input,'circle.in');reset(input);
assign(output,'circle.out');rewrite(output);
read(n,m,k,x);
l:=1;j:=0;a[0]:=1;
repeat
t:=l;
l:=(l*10)mod n;
inc(j);
a[j]:=l;
until (l=1)or(l=0)or(l=t);
j:=j-1;
if (l=t)and(k>j) then k:=n
else k:=k mod n;
x:=((x mod n)+(m mod n)*(a[k] mod n)mod n)mod n;
writeln(x);
close(input);
close(output);
end.
