var a,b,c:array[0..1000000]of longint;
    n,p,i,j,max,zo1,max1:longint;
//=========================
function zd(x,y:longint):longint;
 begin
  if x>y then zd:=x
         else zd:=y;
 end;
//==========================
begin
assign(input,'number.in');reset(input);
assign(output,'number.out');rewrite(output);
 readln(n,p);
 for i:=1 to n do
  read(a[i]);
 b[1]:=a[1];max:=a[1];
 b[0]:=0;
 for i:=2 to n do
  begin
   if a[i-1]<>0 then
   max:=zd(max,max+a[i])
   else max:=zd(max,a[i]);
   b[i]:=max;
  end;
 c[1]:=b[1];c[2]:=c[1]+b[1];
 max:=c[1]+b[1];max1:=max;
 for i:=3 to n do
  begin
   max:=zd(max,c[i-1]+b[i-1]);
   c[i]:=max;
  end;
 if max<c[1] then max:=c[1];
 max:=max mod p;
 writeln(max);
close(input);close(output);
end.
