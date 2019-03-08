program count;
var  n,i,j,k,w,x,num:longint;
procedure dd(a:longint);
var i,j:longint;
begin
  while a>0 do
  begin
    if a mod 10 =x then inc(num);
    a:=a div 10;
  end;
end;

begin
  assign(input,'count.in'); reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(n,x);
  num:=0;
  for i:=1 to n do
    dd(i);
  write(num);
  close(input);
  close(output);
end.

