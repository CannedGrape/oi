 program  ex;
 var  i,j,k,l,m,n:longint;    a,b,c:array[1..1000000] of longint;
 f1,f2:text;
 begin
 assign(f1,'number.in');
 assign(f2,'number.out');
 reset(f1);
 rewrite(f2);
 read(f1,n,m);
     for i:=1  to  n  do
     read(f1,a[i]);
     b[1]:=a[1];
     c[1]:=b[1];
     for i:=2 to n do
     begin
     b[i]:=a[i];
     begin
      for j:=1 to i-1 do
      begin
         b[i]:=b[i]+a[j];
          end;
       if  b[i]<b[i-1]  then b[i]:=b[i-1];
     end;
     end;
     for i:=2  to  n  do
     begin
     c[i]:=c[i-1]+b[i-1];
   if c[i]<c[i-1]  then  c[i]:=c[i-1];
   end;
     write(f2,c[n]);
       close(f1);
       close(f2);
       end.

