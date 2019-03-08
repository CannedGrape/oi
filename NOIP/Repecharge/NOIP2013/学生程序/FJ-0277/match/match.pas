var a,b,s1,s2:array[1..100000] of longint;
    i,j,n,ans:longint;
    k,t:array[1..100000] of real;
    x1,x2,y1,y2:real;
function pd(a,b:real):boolean;
 begin
   if (a-b<0.000000001) and (a-b>-0.000000001) then exit(true)
   else exit(false);
 end;
function xj:boolean;
 var x,y:real;
 begin
   if pd(k[i],0) then
    begin
      y:=i*k[j]+b[j];
      if (y>=0) and (y-1<=0) then exit(true)
      else exit(false);
    end;
   if pd(k[j],0) then
    begin
      y:=j*k[i]+b[i];
      if (y>=0) and (y-1<=0) then exit(true)
      else exit(false);
    end;
   x:=(t[j]-t[i])/(k[i]-k[j]);
   y:=x*k[i]+t[i];
   if (x-1>=0) and (x-n<=0) and (y>=0) and (y-1<=0) then exit(true)
   else exit(false);
 end;
procedure qsort1(l,r:longint);
 var i,j,x,y:longint;
 begin
   if r-l+1<=7 then
    begin
      for i:=l to r-1 do
       for j:=i+1 to r do
        if (a[i]>a[j]) then
         begin
           y:=a[i];
           a[i]:=a[j];
           a[j]:=y;
           y:=s1[i];
           s1[i]:=s1[j];
           s1[j]:=y;
         end;
      exit;
    end;
   i:=l;
   j:=r;
   x:=a[(l+r) div 2];
   repeat
     while (a[i]<x)  do inc(i);
     while (a[j]>x)  do dec(j);
     if i<=j then
      begin
        y:=a[i];
        a[i]:=a[j];
        a[j]:=y;
        y:=s1[i];
        s1[i]:=s1[j];
        s1[j]:=y;
        inc(i);
        dec(j);
      end;
   until i>j;
   if l<j then qsort1(l,j);
   if i<r then qsort1(i,r);
 end;

procedure qsort2(l,r:longint);
 var i,j,x,y:longint;
 begin
   if r-l+1<=7 then
    begin
      for i:=l to r-1 do
       for j:=i+1 to r do
        if (b[i]>b[j]) then
         begin
           y:=b[i];
           b[i]:=b[j];
           b[j]:=y;
           y:=s2[i];
           s2[i]:=s2[j];
           s2[j]:=y;
         end;
      exit;
    end;
   i:=l;
   j:=r;
   x:=b[(l+r) div 2];
   repeat
     while (b[i]<x)  do inc(i);
     while (b[j]>x)  do dec(j);
     if i<=j then
      begin
        y:=b[i];
        b[i]:=b[j];
        b[j]:=y;
        y:=s2[i];
        s2[i]:=s2[j];
        s2[j]:=y;
        inc(i);
        dec(j);
      end;
   until i>j;
   if l<j then qsort2(l,j);
   if i<r then qsort2(i,r);
 end;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do
   begin
     read(a[i]);
     s1[i]:=i;
     s2[i]:=i;
   end;
  readln;
  for i:=1 to n do read(b[i]);
  qsort1(1,n);
  qsort2(1,n);
  for i:=1 to n do
   begin
     x1:=s1[i];
     x2:=s2[i];
     if s1[i]=s2[i] then k[s1[i]]:=0
     else
      begin
        y1:=x2-x1;
        y2:=1.0;
        k[s1[i]]:=y2/y1;
        t[s1[i]]:=-x1*k[s1[i]];
      end;
   end;
  ans:=0;
  for i:=1 to n-1 do
   for j:=i+1 to n do
    if pd(k[i],k[j])=false then
     if xj=true then inc(ans);
  writeln(ans);
  close(input);close(output);
end.

