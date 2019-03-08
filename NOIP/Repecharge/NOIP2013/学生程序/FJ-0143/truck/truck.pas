program truck;
var
 f:array[1..10000,1..10000] of boolean;
 z:array[1..10000,1..10000] of longint;
 a,b:array[1..30000] of longint;
 x,y,k,i,j,n,m,q:longint;
begin
 assign(input,'truck.in');reset(input);
 assign(output,'truck.out');rewrite(output);
 fillchar(f,sizeof(f),false);
 readln(n,m);
 for i:=1 to m do
 begin
 readln(x,y,z[x,y]);
 f[x,y]:=true;
 end;
 for i:=1 to m do
 for j:=1 to m do
  begin
  if f[i,j] then
  begin
  for k:=1 to m do
   if f[j,k] then
   begin
   f[i,k]:=true;
   if z[i,j]<=z[j,k] then z[i,k]:=z[i,j] else z[i,k]:=z[j,k];
   end;
   end;
   end;
 readln(q);
 for i:=1 to q do
 begin
 readln(a[i],b[i]);
 if f[a[i],b[i]] then
 writeln(z[a[i],b[i]])
 else
 writeln('-1');
 end;
 close(input);close(output);
end.
