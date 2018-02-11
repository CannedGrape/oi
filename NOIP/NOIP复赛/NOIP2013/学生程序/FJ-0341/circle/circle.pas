program circle;
var i,j,m,n,k,x,g,gcd:longint; h:int64;
    a:array[1..10000]of integer;
procedure tr(a,b:longint);
var i,j:longint;
begin
if b<>0 then begin i:=b; j:=a mod b; end;
if j=0 then gcd:=i else  tr(i,j);
end;

begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n,m,k,x);
tr(n,m);
j:=gcd; h:=1;
if k<19 then begin
for i:=1 to k do h:=h*10;
j:=n div j;
i:= h mod j;
x:=(x+i*m) mod n;
write(x);end
else if 1000000000000000000mod j =0 then write(x) else
 begin i:=1000000000000000000mod j ;x:=(x+i*m) mod n; write(x);end;

close(input);
close(output);
end.
