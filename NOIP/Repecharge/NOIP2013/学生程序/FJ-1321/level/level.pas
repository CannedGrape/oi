program level;
var n,m:longint;
    f1,f2:text;
begin
assign(f1,'level.in');
assign(f2,'level.out');
reset(f1);
rewrite(f2);
read(f1,n,m);
write(f2,m);
close(f1);
close(f2);
end.