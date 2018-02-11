var sum,n,i,d,t,ans:longint;
   a:array[0..1000000]of longint;
begin
assign(input,'flower.in');
assign(output,'flower.out');
reset(input);
rewrite(output);
  readln(n);
  for i:=1 to n do
  read(a[i]);

  t:=maxlongint;
  d:=0;
  for i:=1 to n do
  if ((a[i]>t)and(d=1)) or
     ((a[i]<t)and(d=0)) then
     begin
     inc(sum);
     d:=1-d;
     t:=a[i];
     end
  else
     t:=a[i];
  ans:=sum;

  sum:=0;
  t:=-maxlongint;
  d:=1;
   for i:=1 to n do
  if ((a[i]>t)and(d=1)) or
     ((a[i]<t)and(d=0)) then
     begin
     inc(sum);
     d:=1-d;
     t:=a[i];
     end
  else
     t:=a[i];

  if sum>ans then writeln(sum)
  else
  writeln(ans);
close(input);
close(output); 
end.

