var n,m,k,x,a:int64;
function power(x,y:int64):int64;
var f,z:int64;
begin
  f:=x;z:=1;
  while y>0 do
  begin
    if y and 1=1 then z:=z*f mod n;
    f:=f*f mod n;
    y:=y shr 1;
  end;
  exit(z);
end;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);rewrite(output);
  readln(n,m,k,x);
  a:=power(10,k)*m mod n;
  a:=a+x;
  writeln(a mod n);
close(input);close(output);
end.