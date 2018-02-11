program chen_4;
var f1,f2:text;
    n,m:integer;
begin
assign(f1,'level.in'); reset(f1);
assign(f2,'level.out'); rewrite(f2);
readln(f1,n,m);
if n<=10 then writeln(f2,m);
if (n>10) and (n<=50) then writeln(f2,'5');
if (n>50) and (n<=100) then writeln(f2,'8');
if n>100 then writeln(f2,'12');
close(f1); close(f2);
end.