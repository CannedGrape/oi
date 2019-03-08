program expr;
var a:array[0..100000] of longint;
    b:array[1..100000] of char;
    i:longint;
begin
assign(input,'expr.in');
reset(input);
assign(output,'expr.out');
rewrite(output);
read(a[0]);
a[0]:=a[0] mod 10000;
for i:=1 to 100000 do
begin
if not eoln then
begin
read(b[i]);
read(a[i]);
end;
a[i]:=a[i] mod 10000;
end;
for i:=1 to 99999 do
begin
if b[i]='*' then a[i]:=((a[i]*a[i-1]) mod 10000) else
begin
if b[i+1]='+' then a[i]:=((a[i]+a[i-1]) mod 10000) else
begin
a[i]:=((a[i]*a[i+1]+a[i-1]) mod 10000);
a[i+1]:=1;
end;
end;
end;
if b[100000]='+' then a[100000]:=((a[100000]+a[99999]) mod 10000) else
a[100000]:=((a[100000]*a[99999]) mod 10000);
write(a[100000]);
close(input);
close(output);
end.
