program ye;
var n,m,i,j,t,k:longint;
    a1,b1,a2,b2,c:array[0..100010] of longint;
procedure qsort(l,r:longint);
 var i,j,x,y:longint;
 begin
  i:=l;
  j:=r;
  x:=c[(l+r) div 2];
  repeat
   while c[i]<x do inc(i);
   while x<c[j] do dec(j);
   if not(i>j) then
    begin
     y:=c[i];
     c[i]:=c[j];
     c[j]:=y;
     inc(i);
     j:=j-1;
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
 end;
begin
 assign(input,'match.in'); reset(input);
 assign(output,'match.out'); rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   read(a1[i]);
   c[i]:=a1[i];
  end;
 qsort(1,n);
 for i:=1 to n do
  for j:=1 to n do
   if a1[i]=c[j] then
    a2[i]:=j;
 for i:=1 to n do
  begin
   read(b1[i]);
   c[i]:=b1[i];
  end;
 qsort(1,n);
 for i:=1 to n do
  for j:=1 to n do
   if b1[i]=c[j] then
    b2[i]:=j;
 t:=0;
 for i:=1 to n do
  if a2[i]<>b2[i] then
   for j:=i+1 to n do
    if a2[i]=b2[j] then
     begin
      k:=b2[i];
      b2[i]:=b2[j];
      b2[j]:=k;
      inc(t);
      if t>99999997 then t:=t mod 99999997;
      break;
     end;
 writeln(t);
 close(input); close(output);
end.

