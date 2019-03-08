var
a,c,d:array[-1..1000000] of longint;
b:array[-1..1000000] of boolean;
i,j,m,n,o,p,max:longint;
begin
assign(input,'number.in');reset(input);assign(output,'number.out');rewrite(output);
fillchar(b,sizeof(b),false);
fillchar(a,sizeof(a),0);
fillchar(c,sizeof(c),0);
readln(n,p);
for i:=1 to n do
begin
read(a[i]);
if a[i]<=0 then b[i]:=false
else b[i]:=true;
end;
readln;
for i:=1 to n do
begin
max:=-maxlongint;
for j:=1 to i do
if b[j] then c[i]:=c[i]+a[j]
else if max<a[j] then max:=a[j];
if c[i]=0 then c[i]:=max;
end;
a[1]:=c[1];
max:=-maxlongint;
for i:=2 to n do
begin
for j:=1 to i-1 do
if max<a[j]+c[j] then max:=a[j]+c[j];
a[i]:=max;
max:=-maxlongint;
end;
for i:=1 to n do if max<a[i] then max:=a[i];
if max<0 then writeln(-(abs(max)mod p))
else writeln(max mod p);
close(input);close(output);
end.
