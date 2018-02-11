var
 i,j,k,x,y,sum,z,n,p,max1,ans,max:longint;
 opt,a,s:array[0..1000000] of longint;

function maxx(a,b:longint):longint;
 begin
  if a<b
   then
    exit(b)
   else
    exit(a);
 end;

begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 readln(n,p);
 for i:=1 to n do
  read(a[i]);
 for i:=3 to n do
  begin
   max:=-maxlongint;
   sum:=0;
   for k:=1 to i-1 do
    begin
     sum:=0;
     for j:=k to i-1 do
      sum:=sum+a[j];
     if max<sum
      then
       max:=sum;
     sum:=0;
     for j:=k downto 1 do
      sum:=sum+a[j];
     if max<sum
      then
       max:=sum;
     if max1<a[k]
      then
       max1:=a[k];
    end;
{   for k:=i-1 downto 1 do
    begin
     sum:=0;
     for j:=k to i-1 do
      sum:=sum+a[j];
     if max<sum
      then
       max:=sum;
    end;        }
   opt[i]:=maxx(a[i]+max,a[i]+max1);
  end;
 opt[1]:=a[1];
 opt[2]:=a[1]+a[2];
 s[1]:=opt[1];
 max:=-maxlongint;
 for i:=2 to n do
  begin
   for j:=1 to i-1 do
    begin
     if max<opt[j]+s[j]
      then
       max:=opt[j]+s[j];
    end;
   s[i]:=max;
  end;
 max:=-maxlongint;
 for i:=1 to n do
  if s[i]>max
   then
    max:=s[i];
 writeln(max mod p);
 close(input);
 close(output);
end.

