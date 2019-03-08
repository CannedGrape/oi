program  ex;
var  i,j,k,l,m,n:integer;   f1,f2:text;       a,b:array[1..1000] of  integer;
begin
assign(f1,'level.in');
assign(f2,'level.out');
reset(f1);
rewrite(f2);
read(f1,n,m);
if  n<10    then write(f2,m);
if  (n>10)  and  (n<100)  then
begin
 l:=n  mod 10;
 write(f2,l);
 end;
 close(f1);
 close(f2);
 end.
