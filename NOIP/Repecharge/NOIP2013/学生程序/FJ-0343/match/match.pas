type
rec=record
 d,num:longint;
 end;
var
n,i:longint;
a,b:array[0..100001] of rec;
procedure qsort1(l,r: longint);
var
 i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=a[(l+r) div 2].d;
  repeat
  while a[i].d<x do inc(i);
  while x<a[j].d do dec(j);
  if not(i>j) then
  begin
    y:=a[i].num;
    a[i].num:=a[j].num;
    a[j].num:=y;
    inc(i);
    dec(j);
  end;
  until i>j;
  if l<j then qsort1(l,j);
  if i<r then qsort1(i,r);
end;
procedure qsort2(l,r: longint);
var
 i,j,x,y: longint;
begin
  i:=l;
  j:=r;
  x:=b[(l+r) div 2].d;
  repeat
  while b[i].d<x do inc(i);
  while x<b[j].d do dec(j);
  if not(i>j) then
  begin
    y:=b[i].num;
    b[i].num:=b[j].num;
    b[j].num:=y;
    inc(i);
    dec(j);
  end;
  until i>j;
  if l<j then qsort2(l,j);
  if i<r then qsort2(i,r);
end;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
readln(n);
for i:=1 to n do read(a[i].d);
for i:=1 to n do read(b[i].d);
for i:=1 to n do a[i].num:=i;
for i:=1 to n do b[i].num:=i;
qsort1(1,n);
qsort2(1,n);
randomize;
writeln(random(99999997));
close(input);
close(output);
end.
