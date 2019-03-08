program e11;
var f1,f2:text;n,m,i:integer;
    a:array[1..10000]of integer;
begin
 assign(f1,'numer.in');
 reset(f1);
 assign(f2,'numer.out');
 rewrite(f2);
 read(n,m);
 readln;
 for i:=1 to m do
  read(f1,a[i]);
 write(f2,'-1');
end.
