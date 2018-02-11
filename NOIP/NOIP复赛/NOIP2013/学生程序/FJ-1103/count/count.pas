program count;
var x:shortint;
    n,b:longint;
    i:integer;
begin
assign(input,'count.in');
reset(input);
assign(output,'count.out');
rewrite(output);
read(n,x);
b:=0;
if n<10 then
begin
for i:=1 to n do
if x=i then inc(b);
end else
begin
if n<100 then
begin
for i:=1 to n do
begin
if x=(i mod 10) then inc(b);
if x=(i div 10) then inc(b);
end;
end else
begin
if n<1000 then
begin
for i:=1 to n do
begin
if x=(i mod 10) then inc(b);
if x=((i div 10) mod 10) then inc(b);
if x=(i div 100) then inc(b);
end;
end else
begin
if n<10000 then
begin
for i:=1 to n do
begin
if x=(i mod 10) then inc(b);
if x=((i div 10) mod 10) then inc(b);
if x=((i div 100) mod 10) then inc(b);
if x=(i div 1000) then inc(b);
end;
end else
begin
if n<100000 then
begin
for i:=1 to n do
begin
if x=(i mod 10) then inc(b);
if x=((i div 10) mod 10) then inc(b);
if x=((i div 100) mod 10) then inc(b);
if x=((i div 1000) mod 10) then inc(b);
if x=(i div 10000) then inc(b);
end;
end else
if n<1000000 then
begin
for i:=1 to n do
begin
if x=(i mod 10) then inc(b);
if x=((i div 10) mod 10) then inc(b);
if x=((i div 100) mod 10) then inc(b);
if x=((i div 1000) mod 10) then inc(b);
if x=((i div 10000) mod 10) then inc(b);
if x=(i div 100000) then inc(b);
end;
end;
end;
end;
end;
end;
if n=1000000 then
begin
for i:=1 to n-1 do
begin
if x=(i mod 10) then inc(b);
if x=((i div 10) mod 10) then inc(b);
if x=((i div 100) mod 10) then inc(b);
if x=((i div 1000) mod 10) then inc(b);
if x=((i div 10000) mod 10) then inc(b);
if x=(i div 100000) then inc(b);
end;
if x=1 then inc(b);
if x=0 then b:=b+6;
end;
write(b);
close(input);
close(output);
end.