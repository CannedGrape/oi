var i,j,k,l,m,n,x,p,y,t:longint;
    a,b:array[0..1000000] of longint;
procedure jn(l,r:longint);
 var i,j,t,k:longint;
  begin
   i:=l;j:=r;k:=a[(l+r)div 2];
   repeat
    while a[i]<k do inc(i);
    while a[j]>k do dec(j);
    if i<=j then
      begin
       t:=a[i];
       a[i]:=a[j];
       a[j]:=t;
       inc(i);
       dec(j);
      end;
    until i>j;
    if i<r then jn(i,r);
    if j>l then jn(l,j);
 end;
 begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
   read(n,p);
   for i:=1 to n do
    begin
    b[i]:=i;
    read(a[i]); end;
   jn(1,n);
   if a[n]<0 then write(a[n])
   else begin
     for i:=1 to n do
       a[i]:=(a[i-1]+a[i]) mod p;
      for i:=1 to n do
       a[i]:=a[i]+b[i];
       write(a[n]+1);
      end;
   close(input);
   close(output);
  end.