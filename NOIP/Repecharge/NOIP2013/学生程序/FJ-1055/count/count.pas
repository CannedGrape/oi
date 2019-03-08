var b,a,n,x,i,count:longint;
begin
assign(input,'count.in');
assign(output,'count.out');
reset(input);
rewrite(output);
read(n,x);
count:=0;
for i:=1 to n do begin a:=i;
while(a>0) do
begin
  b:=a mod 10;
  if(b=x)then  inc(count);
  a:=a div 10;
end;
end;
write(count);
close(input);
close(output);
end.
