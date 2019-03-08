var n,m,k,mi,ni,q,t,i:longint; x,mo,b:int64;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n,m,k,x);
ni:=n;mi:=m ;
while(ni>0)and(mi>0)do  begin
mi:=mi mod ni;
if mi>0 then
ni:=ni mod mi  end;
if ni>0 then b:=n div ni*m else b:=n div mi *m;
t:=10; mo:=10 mod b;

for i:=2 to k do begin
mo:=mo*10 mod b; end;

x:=(x+mo*m)mod n;
writeln(x);
close(input);
close(output);


end.
