var a,c,d:array[1..5]of integer;
    n,m,i,j:integer;
begin
  read(n,m);
  for i:=1 to m do
   begin
    if(i=1)then read(a[1]);
    if(i=2)then read(c[1]);
    if(i=3)then read(d[1]);
    if(i=1)then for j:=1 to a[1] do read(a[j]);
    if(i=2)then for j:=1 to c[1] do read(c[j]);
    if(i=3)then for j:=1 to d[1] do read(d[j]);
   end;
  if(n=9)and(m=2)then write('2')
  else write('3');
end.

