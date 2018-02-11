
 var
  a:array[1..100000] of longint;
  i,j,k,ans,n,max,ans1:longint;


 procedure open;
 begin
   assign(input,'flower.in');
   assign(output,'flower.out');
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
  i:longint;
 begin
   readln(n);
   for i:=1 to n do read(a[i]);
   ans:=0;max:=0;
 end;



 begin
   open;
   datain;

   for i:=2 to n-1 do
   begin
     ans:=0;
     for j:=1 to i-1 do if a[j]<a[j+1] then inc(ans) else break;
     for j:=i+1 to n-1 do if a[j]>a[j+1] then inc(ans) else break;
     if ans>max then max:=ans;
     ans:=0;
     for j:=1 to i-1 do if a[j]>a[j+1] then inc(ans) else break;
     for j:=i+1 to n-1 do if a[j]<a[j+1] then inc(ans) else break;
     if ans>max then max:=ans;
   end;

   writeln(max);
   clo;
 end.
