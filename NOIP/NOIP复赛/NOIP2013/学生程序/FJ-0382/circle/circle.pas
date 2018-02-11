program circle;

var  n,m,x,k:longint;
     a,b,c:longint;
     q,w,e,r,t:longint;
     i,l:longint;
     z:longint;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);

{main}
read(n);
read(m);
read(k);
read(x);

a:=n;
b:=m;
c:=a mod b;

while c<>0 do
begin
a:=b;
b:=c;
c:=a mod b;
end;

z:=n div b;

q:=1;
w:=0;
while not(q>z) do
begin
q:=q*10;
w:=w+1;
end;

e:=q mod z;
r:=k mod q;

t:=1;
for i:=1 to r do
   t:=t*10;

{real main}
for i:=1 to (t+e) do
    begin
        if x>=(n-m) then x:=x-(n-m)
                    else x:=x+m;
    end;

writeln(x);


close(input);
close(output);
end.
