program rv4;
var a,n,i,b:longint; c:array[1..1000] of integer;
f1,f2:text;
begin
assign(f1,'number.in');
assign(f2,'number.out');
reset(f1);
rewrite(f2);
readln(f1,a,n);
for i:=1 to a do read(f1,c[i]);
write(f2,c[a]);
close(f1);
close(f2);
end.

