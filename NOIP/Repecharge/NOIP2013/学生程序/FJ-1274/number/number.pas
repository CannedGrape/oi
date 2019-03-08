var a,b,c,d:array[1..10000000]of longint;
    p:boolean;
    i,j,w,n,m,max:longint;
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
read(n,m);
for i:=1 to n do read(a[i]);
b[1]:=a[1];
c[1]:=a[1];
for i:=2 to n do
begin
w:=0; p:=false;
for j:=1 to i do
if a[j]>0 then w:=w+a[j];
if w>0 then b[i]:=w
else begin
for j:=1 to i do
if a[j]=0 then begin b[i]:=0; p:=true; end;
if not p then begin
w:=a[1];
for j:=1 to i do if a[j]>w then w:=a[j];
b[i]:=w;
end;
end;
end;
d[1]:=b[1]+c[1];
c[2]:=d[1];
for i:=2 to n do begin
d[i]:=b[i]+c[i];
for j:=1 to i do
if d[j]>max then max:=d[j];
c[i+1]:=max;
end;
max:=c[1];
for i:=1 to n do if c[i]>max then max:=c[i];
writeln(max mod m);
close(input);close(output);
end.