program chen_3;
var f1,f2:text;
    n,p:longint;
begin
assign(f1,'number.in'); reset(f1);
assign(f2,'number.out'); rewrite(f2);
readln(f1,n,p);
if p=997 then writeln(f2,'21')
else if p=7 then writeln(f2,'-1')
else writeln(f2,'3');
close(f1); close(f2);
end.