var
  i,j,k,m,n:longint;
  a,b,h:array[0..100000] of longint;
begin
  assign(input,'flower.in');  reset(input);
  assign(output,'flower.out');  rewrite(output);
  readln(n);
  for i:=1 to n do
   read(h[i]);
  a[1]:=1;  b[1]:=1;
  for i:=2 to n do
   for j:=1 to n-1 do
    begin
     if h[i]>h[j]  then
       if b[j]+1>a[i] then a[i]:=b[j]+1;
     if h[i]<h[j]  then
       if a[j]+1>b[i] then b[i]:=a[j]+1;
    end;
  m:=0;
  for i:=1 to n do
   begin
    if a[i]>m then m:=a[i];
    if b[i]>m then m:=b[i];
   end;
  write(m);
  close(input);  close(output);
end.
