program  ex;
var  a,b:array[1..1000] of  string;
s1,s2:string;  i,j,k,l,m,n:integer;     f1,f2:text;
begin
assign(f1,'expr.in');
assign(f2,'expr.out');
reset(f1);
rewrite(f2);
readln(f1,s1);
l:=length(s1);
for i:=l-3 to l do
write(f2,s1[i]);
close(f1);
close(f2);
end.
