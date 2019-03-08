program count;
var n,a,x,i,y,z:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  a:=n;
  z:=1;
  if n mod 10>=x then y:=n div 10+1
  else y:=n div 10;
  for i:=1 to 5 do
  begin
    z:=z*10;
    n:=n div 10;
    if n mod 10>x then y:=y+(n div 10+1)*z
    else if n mod 10<x then y:=y+(a div 10)
    else y:=y+a mod z+1;
    if n<10 then break;
  end;
  writeln(y);
  close(input);
  close(output);
end.