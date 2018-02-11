program work;
var a,b,c:int64;
    i,j,n,m,k,x:int64;
procedure init;
begin
 assign(input,'circle.in');
  assign(output,'circle.out');
  reset(input);
  rewrite(output);
end;
procedure oover;
begin
 close(input);
 close(output);
end;
function mi(x,k:int64):int64;
begin
 mi:=1;
 while k>0 do
 begin
  if k and 1=1 then mi:=mi*x mod n;
  x:=x*x mod n;
  k:=k shr 1;
 end;
end;
begin
 init;
 read(n,m,k,x);
 m:=(m*mi(10,k)+x)mod n;
 writeln(m);
oover;
end.
