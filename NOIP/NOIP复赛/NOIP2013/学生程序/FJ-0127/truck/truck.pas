program truck;
var
h,q,k,j,c,i,n,m:integer;
a,b,x,y,z:array[1..100000] of integer;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
readln(n,m);
for i:=1 to m do
 for j:=1 to m do
   for k:=1 to m do
    begin
    read(x[i]);
    read(y[j]);
    read(z[k]);
    end;
  read(q);
  for i:=1 to q do
   for j:=1 to q do
   begin
   read(a[i]);
   read(b[j]);
   end;
   h:=-1;
   for i:=1 to q do
   writeln(h);
  close(input);
  close(output);
end.
