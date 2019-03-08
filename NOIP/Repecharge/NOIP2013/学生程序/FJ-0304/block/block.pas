program ex;
var n,m,i,j,k,l:longint;
h,c:array[1..100000]of longint;


function  min2(l,r:longint):longint;
var mid,k,k1:longint;
begin
if l=r then exit(l)
else begin
mid:=(l+r)div 2;
k:=l;
k1:=min2(l,mid);
if h[k]>h[k1] then k:=k1;
k1:=min2(mid+1,r);
if h[k]>h[k1] then k:=k1;
min2:=k;
end;
end;


procedure find(l,r:longint);
var min,i,j:longint;
begin
min:=maxlongint;
j:=min2(l,r);
min:=h[j];
k:=k+min;
for i:=l to r do
dec(h[i],min);
if (l<=j-1) then find(l,j-1);
if (r>=j+1) then find(j+1,r);
end;



begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
readln(n);
for i:=1 to n do
begin
read(h[i]);
end;
k:=0;
find(1,n);
writeln(k);
close(input);
close(output)
end.
