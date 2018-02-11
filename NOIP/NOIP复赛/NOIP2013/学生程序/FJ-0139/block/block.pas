var a,b:array[0..10000] of longint;
q,w,e,r,t,y,u,i,o,p,s,d,f,g,h,j,k,l,z,x,v,n,m:longint;
begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
readln(n);p:=1;h:=-1;t:=0;
for i:=1 to n do
begin
read(a[i]);
b[i]:=0;
end;
repeat
d:=0;
h:=h+1;
for i:=n downto 1 do
begin
if b[i]<>a[i] then d:=1;
if (b[i]=a[i]) and (i<>n) then begin h:=h+1;
if  (b[i-1]=a[i-1]) then h:=h-1;
end;
if (b[i]=a[i]) and (i<>n) then continue;
if (b[i]=a[i]) and (i=n)then n:=n-1;
b[i]:=b[i]+1;
end;
until(d=0);
write(h);
close(input);close(output);
end.
