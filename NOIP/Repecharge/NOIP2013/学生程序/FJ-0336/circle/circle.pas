var a,b:array[1..1000000]of longint;
    i,n,m,k,x,j,y,ci,s:longint;
begin
assign(input,'circle.in');
reset(input);
assign(output,'circle.out');
rewrite(output);
  read(n,m,k,x);ci:=1;
  for j:=1 to k do ci:=ci*10;
  for i:=1 to n do
   begin
    a[i]:=i-1;
    b[i]:=i-1;
   end;
  for y:=1 to ci do
   for i:=1 to n do
    begin
     a[i]:=a[i]-m;
     if a[i]<0 then a[i]:=a[i]+n;
    end;
  for i:=1 to n do
   if b[x+1]=a[i] then s:=b[i];
  write(s);
close(input);
close(output);
end.
