var
a:array[0..10] of longint;
o,i,j,m,n,nn,an:longint;
begin
assign(input,'count.in');reset(input);assign(output,'count.out');rewrite(output);
readln(n,nn);
m:=1;an:=0;
for i:=1 to n do
begin
if i=10 then inc(m);
if i=100 then inc(m);
if i=1000 then inc(m);
if i=10000 then inc(m);
if i=100000 then inc(m);
if i=1000000 then inc(m);
o:=i;
for j:=1 to m do
begin
if o mod 10=nn
then inc(an);
o:=o div 10;
end;
end;
writeln(an);
close(input);close(output);
end.