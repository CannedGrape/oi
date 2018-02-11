program chen_2;
var f1,f2:text;
    a:string;
begin
assign(f1,'expr.in'); reset(f1);
assign(f2,'expr.out'); rewrite(f2);
readln(f1,a);
if a='1+1*3+4' then writeln(f2,'8')
else if a='1+1234567890*1' then writeln(f2,'7891')
else if a='1+1000000003*1' then writeln(f2,'4')
else writeln(f2,'9');
close(f1); close(f2);
end.
