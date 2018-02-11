
var
q,i:integer;
x,xx,n,m:longint;
k,kk:int64;

procedure pan;
var i:integer;
begin
i:=n-m;
if (m=1) or (i=1) then q:=n-1;
if n mod m = 0 then q:=n div m else q:=n;
if n mod i = 0 then q:=n div i;
end;

begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
readln(n,m,k,x);
kk:=1;
for i:=1 to k do
 begin
  kk:=10*kk;
if (i mod 10=0) then kk:=kk mod n;


  end;
xx:=x;

if n mod 2 <> 0 then
   begin
    q:=kk mod n;
 for i:=1 to q do
   begin
   xx:=xx+m;
    if xx>n then xx:=xx-n;
end;
end;
if n mod 2= 0 then begin pan;
   q:=kk mod q;
 for i:=1 to q do
   begin
   xx:=xx+m;
    if xx>n then xx:=xx-n;
end;
end;

writeln(xx);
close(input);
close(output);
end.
