program number;
var a,b,c:array[1..1000000]of longint;
n,p,i,j,t,max:longint;
begin
 assign(input,'number.in');reset(input);
 assign(output,'number.out');rewrite(output);
 readln(n,p);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
 begin
  t:=0;
  for j:=1 to i-1 do
  begin
   t:=t+a[j];
   if (t<0) then t:=0;
  end;
  b[i]:=a[i]+t;
 end;
 c[1]:=b[1];
 for i:=2 to n do
 begin
  t:=0;max:=-maxlongint;
  for j:=1 to i-1 do
  begin
   t:=b[j]+c[j];
   if t>max then max:=t;
  end;
  c[i]:=max;
 end;
 max:=-maxlongint;
 for i:=1 to n do if max<c[i] then max:=c[i];
 writeln(max);
 close(input);close(output);
end.
