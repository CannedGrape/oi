var
n,c:longint;
i:longint;
a:array[0..100002] of longint;
ans:int64;

procedure jian(l,r:longint);
var i,j,p,q,o,oo,m:longint;
   min,u:longint;
begin
i:=l;j:=r;o:=1;oo:=1;m:=0;
while a[i]=0 do inc(i);
while a[j]=0 do dec(j);

min:=maxint;u:=0;
p:=i;

while a[p]<>0 do
begin  if (a[p]<min) then begin min:=a[p];u:=p;end;
       inc(p);
       if (a[n]=0) and (c=0) then exit;
end;
repeat
          for q:=i to p-1 do dec(a[q]);
          inc(ans);
until a[u]=0;

if a[oo]=0 then
begin
repeat
if a[o]=0 then inc(m,a[oo]);inc(oo);c:=m;
until oo=n;
if o=n then exit;

end;

if 1<u  then  jian(1,u);
if n>u then  jian(u,n);
end;


begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
readln(n);
c:=maxint;
a[0]:=100000000;a[10002]:=8714200000000000001;
for i:=1 to n do read(a[i]);
jian(1,n);
writeln(ans);
close(input);
close(output);
end.



{end;
repeat
          for q:=i to p-1 do dec(a[q]);
          inc(ans);
until a[u]=0;

if a[oo]=0 then
begin
repeat
if a[o]=0 then inc(m,a[oo]);inc(oo);c:=m;
until oo=n;
if o=n then exit;

end;

if 1<u  then  jian(1,u);
if n>u then  jian(u,n);
end;


begin
assign(input,'block.in');
assign(output,'block.out');
reset(input);
rewrite(output);
readln(n);
c:=maxint;
a[0]:=100;a[10002]:=87451;
for i:=1 to n do read(a[i]);
{for i:=1 to n do read(a[i]);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(a[i]);
for i:=1 to n do read(a[i]);}
jian(1,n);
writeln(ans);
close(input);
close(output);
end.}

