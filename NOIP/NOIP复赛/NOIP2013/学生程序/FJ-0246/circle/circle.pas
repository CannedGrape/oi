program circle;
var n,m,k,x,h,i,t:longint;
  y:int64;
begin
  assign(input,'circle.in');
  reset(input);
  assign(output,'circle.out');
  rewrite(output);
  readln(n,m,k,x);
  if (0<=x) and (x<=n) then
  begin
  y:=1;
  for i:=1 to k do
   y:=y*10;
  if n>=m then
   begin
   if n mod m=0 then
   h:=n div m else
     h:=n;
   end;
  y:=y mod h;
  if y=0 then
   t:=x else
  begin
     t:=x;
   for i:=1 to y do
    begin
     t:=(t+m)mod n;
    end;
  end;
  writeln(t);
end;
close(input);
close(output);
readln;readln;
end.

