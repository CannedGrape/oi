
 var
  a,d,c:array[1..100000] of longint;
  i,j,k,ans,max,n,t,p,tot:longint;


 procedure open;
 begin
   assign(input,'block.in');
   assign(output,'block.out');
   reset(input);
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
   readln(n);
   tot:=0;
   for i:=1 to n do
   begin
     read(a[i]);
     if a[i]=0 then
     begin
       inc(tot);
       d[tot]:=i;
     end;
   end;
 end;

 function ok(l,r:longint):boolean;
 var
  i,j,k:longint;
 begin
   ok:=true;
   for i:=1 to n do if a[i]<>0 then
   begin
     ok:=false;
     break;
   end;
 end;

 procedure qsortaa(s,t:longint);
 var
  i,j,te,x:longint;
 begin
   i:=s;j:=t;x:=a[(i+j)div 2];
   repeat
     while a[i]>x do inc(i);
     while a[j]<x do dec(j);
     if i<=j then
     begin
       te:=a[i];a[i]:=a[j];a[j]:=te;
       inc(i);dec(j);
     end;
   until i>j;
   if s<j then qsortaa(s,j);
   if i<t then qsortaa(i,t);
 end;

 procedure qsorta(s,t:longint);
 var
  i,j,te,x:longint;
 begin
   i:=s;j:=t;x:=a[(i+j)div 2];
   repeat
     while a[i]<x do inc(i);
     while a[j]>x do dec(j);
     if i<=j then
     begin
       te:=a[i];a[i]:=a[j];a[j]:=te;
       inc(i);dec(j);
     end;
   until i>j;
   if s<j then qsorta(s,j);
   if i<t then qsorta(i,t);
 end;


 begin
   open;
   datain;
   while tot=0 do
   begin
     inc(ans);
     for i:=1 to n do
     begin
       dec(a[i]);
       if a[i]=0 then
       begin
         inc(tot);
         d[tot]:=i;
       end;
       inc(a[i]);
     end;
   end;
   if tot=n then
   begin
     writeln(1);
     clo;
     halt;
   end;
   qsorta(1,d[tot]-1);
   inc(ans,a[1]);
   qsortaa(d[tot]+1,n);
   inc(ans,a[n]);
   writeln(ans);
   clo;
 end.













































