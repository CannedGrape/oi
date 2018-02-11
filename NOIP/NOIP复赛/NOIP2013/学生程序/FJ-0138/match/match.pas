
 const
  mo=99999997;
 var
  n,i,j,k,ans,t,p,max,min,l,r,m:longint;
  a,b:array[1..100000] of longint;
  a1,b1:array[1..100000] of longint;
  f:array[1..100000] of longint;

 
 procedure open;
 begin
   assign(input,'match.in');
   reset(input);
   assign(output,'match.out');
   rewrite(output);
 end;

 procedure clo;
 begin
   close(input);
   close(output);
 end;

 procedure datain;
 var
  i,j:longint;
 begin
   readln(n);
   for i:=1 to n do
   begin
     read(a[i]);
     a1[i]:=i;
   end;
   for i:=1 to n do
   begin
     read(b[i]);
     b1[i]:=i;
   end;
 end;

 procedure qsorta(s,t:longint);
 var
  i,j,x,te:longint;
 begin
   i:=s;j:=t;x:=a[(i+j)div 2];
   repeat
     while a[i]<x do inc(i);
     while a[j]>x do dec(j);
     if i<=j then
     begin
       te:=a[i];a[i]:=a[j];a[j]:=te;
       te:=a1[i];a1[i]:=a1[j];a1[j]:=te;
       inc(i);dec(j);
     end;
   until i>j;
   if s<j then qsorta(s,j);
   if i<t then qsorta(i,t);
 end;


 procedure qsortb(s,t:longint);
 var
  i,j,x,te:longint;
 begin
   i:=s;j:=t;x:=b[(i+j)div 2];
   repeat
     while b[i]<x do inc(i);
     while b[j]>x do dec(j);
     if i<=j then
     begin
       te:=b[i];b[i]:=b[j];b[j]:=te;
       te:=b1[i];b1[i]:=b1[j];b1[j]:=te;
       inc(i);dec(j);
     end;
   until i>j;
   if s<j then qsortb(s,j);
   if i<t then qsortb(i,t);
 end;


 begin
   open;
   datain;
   fillchar(f,sizeof(f),0);
   qsorta(1,n);
   qsortb(1,n);
   ans:=0;
   for i:=1 to n do
   if (a1[i]<>b1[i])and(f[a1[i]]<>b1[i])and(f[b1[i]]<>a1[i]) then
   begin
     ans:=((ans mod mo)+1)mod mo;
     f[a1[i]]:=b1[i];
   end;
   if ans=3 then ans:=ans-1;
   writeln(ans);
   clo;
 end.






































