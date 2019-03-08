
 const
  maxl=maxlongint;
 var
  a:array[1..5000,1..5000] of longint;
  i,j,k,t,p,n,m,x,y,z,q:longint;

 procedure open;
 begin
   assign(input,'truck.in');
   reset(input);
   assign(output,'truck.out');
   rewrite(output);
 end;

 procedure clo;
 begin
   close(input);
   close(output);
 end;

 procedure datain;
 var
  i,j,k:longint;
 begin
   readln(n,m);
   for i:=1 to n do
    for  j:=1 to n do
    if i=j then a[i,j]:=0 else a[i,j]:=maxl;
   for i:=1 to m do
   begin
     readln(x,y,z);
     if (a[x,y]=maxl) then
     begin
       a[x,y]:=z;
       a[y,x]:=z;
     end
     else
     if (z>a[x,y]) then
     begin
       a[x,y]:=z;
       a[y,x]:=z;
     end;
   end;
 end;

 function min(l,r:longint):longint;
 begin
   if (l=maxl)or(r=maxl) then min:=maxl;
   if l>r then min:=r else min:=l;
 end;


 procedure floyd;
 var
  i,j,k:longint;
 begin
   for k:=1 to n do
    for i:=1 to n do
    if (i<>k) then
    for j:=1 to n do
    if (i<>j)and(j<>k) then
    if  (a[i,j]<min(a[i,k],a[k,j]))and(a[i,k]<>maxl)and(a[k,j]<>maxl)
     then a[i,j]:=min(a[i,k],a[k,j]);
 end;

 begin
   open;
   datain;
   floyd;
   readln(q);
   for i:=1 to q do
     begin
       readln(x,y);
       if a[x,y]<>maxl then writeln(a[x,y]) else writeln(-1);
     end;
   clo;
 end.































































