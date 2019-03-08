program match;

var a,b,c,d:array [1..1000000] of longint;
    a1,b1,a2,b2,i,g,h,n:longint;


procedure qsorta(a1,a2: longint);
var ai,aj,ax,ay:longint;
begin
ai:=a1;
aj:=a2;
ax:=a[(a1+a2) div 2];
repeat
while a[ai]<ax do
inc(ai);
while ax<a[aj] do;
dec(aj);
if not(ai>aj) then
begin
ay:=a[ai];
a[ai]:=a[aj];
a[aj]:=ay;
inc(ai);
aj:=aj-1;
end;
until ai>aj;
if a1<aj then
qsorta(a1,aj);
if ai<a2 then
qsorta(ai,a2);
end;



procedure qsortb(b1,b2: longint);
var bi,bj,bx,by:longint;
begin
bi:=b1;
bj:=b2;
bx:=b[(b1+b2) div 2];
repeat
while b[bi]<bx do
inc(bi);
while bx<b[bj] do;
dec(bj);
if not(bi>bj) then
begin
by:=b[bi];
b[bi]:=b[bj];
b[bj]:=by;
inc(bi);
bj:=bj-1;
end;
until bi>bj;
if b1<bj then
qsortb(b1,bj);
if bi<b2 then
qsortb(bi,b2);
end;





begin
assign(input,'match.in');
assign(output,'match.out');
reset(input);
rewrite(output);
read(n);
for i:=1 to n do
begin
read(a[i]);
c[i]:=a[i];
end;
for i:=1 to n do
begin
read(b[i]);
d[i]:=b[i];
end;
qsorta(1,n);
qsortb(1,n);
for i:=1 to n do
begin
if a[i]<>c[i] then g:=g+1;
if b[i]<>d[i] then h:=h+1;
end;
if g>h then g:=g-h
       else g:=h-g;
write(g);
close(input);
close(output);
end.

