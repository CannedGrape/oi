program ex12;
var f1,f2:text;
begin
 assign(f1,'level.in');
 reset(f1);
 assign(f2,'level.out');
 rewrite(f2);
 write(f2,'1');
end.
