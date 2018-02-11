program exam1;
 var a,b:array[0..100500]of integer;
     i,j,k,l,m,n:longint;
     x,y,z,q,p,o,zz:longint;
     s:ansistring;
     yy,xx:int64;
 begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
  readln(s);
  l:=1;k:=1;p:=0;s:=s+'+';
  while l<=length(s) do
   begin
    o:=0;
    if (s[l]='+')and(p=0) then
     begin
     if l>4 then
      val(copy(s,l-4,4),a[k])
     else
      val(copy(s,1,l-1),a[k]);
      b[k]:=-1;
      k:=k+1;o:=1;
      delete(s,1,l);
      l:=0;
     end;
    if (o=0)and(s[l]='+')and(p=1) then
     begin
     if l>4 then
      val(copy(s,l-4,4),b[k])
     else
      val(copy(s,1,l-1),b[k]);
      a[k]:=-1;
      k:=k+1;
      delete(s,1,l);
      l:=0;
      p:=0;
      o:=1;
     end;
    if (o=0)and(s[l]='*') then
     begin
     if l>4 then
      val(copy(s,l-4,4),b[k])
     else
      val(copy(s,1,l-1),b[k]);
      a[k]:=-1;
      k:=k+1;
      delete(s,1,l);
      l:=0;
      p:=1;
     end;
    l:=l+1;
   end;
  k:=k-1;xx:=0;yy:=1;
  for i:=1 to k do
   begin
    if a[i]<>-1 then
     begin
      xx:=xx+a[i];
      xx:=xx mod 10000;
     end;
    if b[i]<>-1 then
     begin
      yy:=yy*b[i];
      yy:=yy mod 10000;
      zz:=1;
     end;
   end;
if (zz=1)then
  write((xx+yy)mod 10000)
 else write(xx mod 10000);
close(input);close(output);
 end.