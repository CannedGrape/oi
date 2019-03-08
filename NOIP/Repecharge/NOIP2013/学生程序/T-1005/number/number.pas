var
i,n,p,s,ss,max,m:longint;
a,b:array[1..10000]of longint;
begin
assign(input,'number.in'); reset(input);
assign(output,'number.out'); rewrite(output);
ss:=1;
max:=-10000;
m:=-10000;
readln(n,p);
for i:=1 to n do

read(a[i]);
if a[i]<0 then write('-');
for i:=1 to n do begin



s:=s+a[i];
if s>m then m:=s;
ss:=ss+m-a[i]; if ss>max then  max:=ss;
end;

 writeln(max mod p);
close(input); close(output);
end.

