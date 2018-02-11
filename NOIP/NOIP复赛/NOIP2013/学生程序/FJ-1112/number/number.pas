var
a,b,c:array[1..100]of integer;
s,u,j,i,n,p,m,k,e,l,max:integer;
begin
assign(input,'number.in');
reset(input);
assign(output,'number.out');
rewrite(output);
max:=0;
read(n,p);
for m:=1 to n do read(a[m]);
 b[1]:=a[1];
 for j:=2 to n do
 begin
 for i:=1 to j do
 u:=i;
 while u<>0 do
 begin
 if a[u]>=0 then
b[j]:=a[u]+b[j]
else b[j]:=b[j]+a[j];
 dec(u);
 end;
 end;
 c[1]:=b[1];
 for k:=2 to n do
 begin
 for e:=1 to k-1 do
    l:=e;
    while l<>0 do
    begin
    if (c[e]>=0) and (b[e]>=0)then c[k]:=b[e]+c[e]else
  if (c[e]<0) and (b[e]>=0)then c[k]:=c[e]+b[e]else
   if (c[e]>=0 )and (b[e]<0)then c[k]:=c[e]+c[e]else
      if (c[e]<0) and (b[e]<0)then
      begin
        if (c[e]>b[e])then c[k]:=c[e]+c[e]else
               if (c[e]<b[e])then c[k]:=c[e]+b[e]else
                      c[k]:=c[e]+c[e];
end;
    dec(l);
    end;
     end;
    for s:=1 to n do
if c[s]>max then max:=c[s];
    write(abs(max)mod p);
readln;
readln;
close(input);
close(output);
end.
