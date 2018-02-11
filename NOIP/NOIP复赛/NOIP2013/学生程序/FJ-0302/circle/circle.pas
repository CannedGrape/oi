PROGRAM ex_1;
var l,n,m,k,x1,l2,k2,kk:longint;i:longint;
 function gcf(x,y:longint):longint;
 var y1,t:longint;
 begin
  y1:=y;
  while x mod y <>0 do
   begin
    t:=x mod y;
    x:=x*t;
    y:=t;
   end;
  gcf:=x;
 end;
function gfc(x:longint):longint;
 var ll:longint;
 begin
  ll:=0;
  while x div 10<>0 do
   begin
    inc(ll);
    x:=x div 10;
   end;
  gfc:=ll;
 end;
begin
 assign(input,'circle.in');
 reset(input);
 read(n,m,k,x1);
 l:=gcf(n,m);
 if k mod 2 =1 then k:=gfc(n)
  else k:=gfc(n)+1;
 kk:=round(exp(ln(10)*k));
 l2:=kk div l;
 k2:=l * l2;
 k2:=kk-k2;
 for i:=1 to k2 do
  begin
   x1:=x1+m;
   if x1>n-1 then
    x1:=x1-n;
  end;
 assign(output,'circle.out');
 rewrite(output);
 write(x1);
 close(input);
 close(output);
end.
