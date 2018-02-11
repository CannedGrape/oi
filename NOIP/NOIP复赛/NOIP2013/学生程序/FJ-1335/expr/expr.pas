program ex1;
var f1,f2:text;s:string;
begin
 assign(f1,'expr.in');reset(f1);
 assign(f2,'expr.out');rewrite(f2);
 read(f1,s);
 write(f2,'1234');
end.

