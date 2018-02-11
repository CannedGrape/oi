program circle;
var a,n,m,k,x,q,w:longint;

begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);

readln(n,m,k,x);

if k<=7 then begin
q:=1;
for a:=1 to k do q:=q*10;
w:=((q mod n)*m) mod n;
x:=x+w;
x:=x mod n;
writeln(x);end

else if k div 2=0 then write(x)
                  else write (((((10 mod n)*m) mod n)+x) mod n);


close(input);close(output);
end.
