program flower;
 var a:array[1..100003] of longint;
  n,i,j,m1,m2,m3,l,r,o,q:longint;
  x:boolean;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
 readln(n);
 for i:=1 to n do
  read(a[i]);
 readln;
 i:=1;
 l:=i+1;
 r:=i+2;
 while i<>n-1 do
  begin
  if ((a[l]>a[i]) and (a[l]>a[r])) or ((a[l]<a[i]) and (a[l]<a[r])) and (a[l]<>0)and (a[i]<>0)and(a[r]<>0)and(a[i]<>-1)and(a[r]<>-1)and(a[l]<>-1) then
  begin
   if (m1<>i)  and (m2<>l) and (m3<>r) then
   begin
   if (m1=0) then o:=o+3;
   if (i=m2)and(l=m3) then o:=o+1
    else
      if (i=m2) and (l<>m3) then o:=o+2;
   m1:=i;
   m2:=l;
   m3:=r;
   inc(i);
   if a[i]=-1 then
     for q:=i to n do
      if a[q]<>-1 then
       begin
       i:=q;
       break;
       end;
   if a[i+1]=-1 then
   begin
   for q:=i+1 to n do
    if a[q]<>-1 then
     begin
     l:=q;
     break;
     end;
   end
  else
   l:=i+1;
   if a[l+1]=-1 then begin
   for q:=i+2 to n do
    if a[q]<>-1 then
     begin
     r:=q;
     break;
     end;
   end
  else
   r:=l+1;
   x:=true;
   end;
  end
  else
   if o<>0 then a[r]:=-1;
  if x=false then inc(r);
  if r=n+1 then begin
   inc(l);
   r:=l+1;
   end;
  if (l=n) and (r=n+1) then
   begin
    inc(i);
    l:=i+1;
    r:=i+2;
   end;
  x:=false;
  end;
 writeln(o);
close(input);
close(output);
end.
