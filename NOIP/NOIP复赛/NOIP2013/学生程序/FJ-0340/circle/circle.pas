program circle;
 var n,m,x,y,i,s,ans,k,q:longint;
begin
assign(input,'circle.in');
assign(output,'circle.out');
reset(input);
rewrite(output);
 readln(n,m,k,x);
 y:=-1;
 while y<>x do
  begin
  if i=0 then y:=x;
   y:=y+m;
   if y>n then y:=y-n;
   inc(i);
  end;
 ans:=1;
 for s:=1 to k do
  begin
   ans:=ans*10;
   ans:=ans mod i;
  end;
  y:=x;
 if ans>0 then
for s:=1 to ans do
begin
 y:=y+m;
 if y>n then y:=y-n;
end
else y:=x;
if y=n then y:=0;
 writeln(y);
close(input);
close(output);
end.
