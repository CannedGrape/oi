program match;
type ab=array[1..100000] of longint;
var i,j,k,h,ans:longint; n,m:longint; a,b,c,d:ab;
    e,f:array[1..26000000]of longint;
procedure tr1(l,h:longint);
var i,j,k,x,z:longint;
begin
i:=l; j:=h; k:=c[(l+h)div 2];
repeat
while (i<j) and (c[i]<k) do inc(i);
while (i<j) and(c[j]>k) do dec(j);
if (i<=j) and (c[i]>=c[j]) then begin x:=c[i];c[i]:=c[j];c[j]:=x;
                                     z:=e[c[i]];e[c[i]]:=e[c[j]];e[c[j]]:=z;
                                      inc(i); dec(j); end;
until(i>j);
if i<h then tr1(i,h);
if j>l then tr1(l,j);
end;
procedure tr2(l,h:longint);
var i,j,k,x:longint;
begin
i:=l; j:=h; k:=d[(l+h)div 2];
repeat
while (i<j) and (d[i]<k) do inc(i);
while (i<j) and(d[j]>k) do dec(j);
if (i<=j) and (d[i]>=d[j]) then begin x:=d[i];d[i]:=d[j];d[j]:=x;
 inc(i); dec(j); end;
until(i>j);
if i<h then tr2(i,h);
if j>l then tr2(l,j);
end;
begin
{assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);}
readln(n);
for i:=1 to n do
begin read(a[i]);  c[i]:=a[i];  e[a[i]]:=i; end;
readln;
for i:=1 to n do
begin read(b[i]); d[i]:=b[i];f[b[i]]:=i; end;
tr1(1,n);  tr2(1,n);

for i:=1 to n do
 begin
 k:= f[d[e[a[i]]]] ;
 h:=b[k];
 for j:=k-1 downto i do b[j+1]:=b[j];
 b[i]:=b[k];ans:=k-i+ans;
 end;
 ans:=ans mod 99999997;
 write(ans);
{ close(input);
 close(output); }
end.

