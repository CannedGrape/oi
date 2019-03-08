program chen_1;
var f1,f2:text;
    a:array[1..1000000] of string[7];
    x:char;
    j,t,c:byte;
    n,i,s:longint;
begin
assign(f1,'count.in'); reset(f1);
assign(f2,'count.out'); rewrite(f2);
readln(f1,n,c);
x:=chr(c+48);
s:=0;
for i:=1 to n do
  begin
  str(i,a[i]);
  t:=length(a[i]);
  for j:=1 to t do if a[i,j]=x then s:=s+1;
  end;
writeln(f2,s);
close(f1); close(f2);
end.