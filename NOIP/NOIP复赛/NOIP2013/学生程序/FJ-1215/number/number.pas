Program HJF_number;
uses math;
var
   mo,sco,temp,sum,asco:array[0..1000] of longint;
   n,p,i,j,l,t,ans:longint;
begin
   assign(input,'number.in');   reset(input);
   assign(output,'number.out');   rewrite(output);
   readln(n,p);
   read(t);

   sum[0]:=0;
   sum[1]:=t;

   mo[0]:=-maxlongint div 2;
   mo[1]:=sum[1];

   sco[0]:=-maxlongint div 2;
   sco[1]:=mo[1];

   temp[0]:=-maxlongint;
   temp[1]:=sum[1];

   asco[0]:=-maxlongint;
   asco[1]:=2*t;

   ans:=t;

   for i:=2 to n do
   begin
      read(t);
      temp[i]:=t;
      sum[i]:=t+sum[i-1];
      for l:=0 to i-1 do
         temp[i]:=max(temp[i],sum[i]-sum[l]);
   end;
   for i:=2 to n do
   begin
      mo[i]:=temp[i];
      for j:=1 to i-1 do
         mo[i]:=max(mo[i],temp[j]);
      sco[i]:=max(asco[i-1],asco[i-2]);
      asco[i]:=max(sco[i]+mo[i],sco[i-1]);
      ans:=max(ans,sco[i]);
   end;
   if ans>=0 then writeln(ans mod p)
   else writeln('-',abs(ans) mod p);
   close(input);
   close(output);
end.
