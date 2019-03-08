Var
 n,m,i,j,k,p,max:longint;
 a,b:array[0..1000]of longint;
begin
 assign(input,'level.in');
 assign(output,'level.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to n do
  a[i]:=1;
 for i:=1 to m do
 begin
  read(p);
  for j:=1 to p do
  begin
   read(b[j]);
   for k:=b[j-1]+1 to b[j]-1 do
    if a[k]>max then max:=max+1;
  end;
  for j:=1 to p do
   a[b[p]]:=max+1;
  max:=0;
 end;
 for i:=1 to n do
  if a[i]>max then max:=a[i];
 write(max);
 close(input);
 close(output);
end.
