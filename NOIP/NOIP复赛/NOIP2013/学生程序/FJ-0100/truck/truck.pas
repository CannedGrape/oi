var
  n,t,i,j,k,l,x,y,p,z,m:longint;
  b:array[1..10000,1..10000]of longint;
  a:array[1..10000,1..50000]of boolean;
  d:array[1..10000]of longint;
function min(a,b:longint):longint;
var t:longint;
begin
  if a>b then min:=b
  else min:=a;
end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    a[x,y]:=true;
    a[y,x]:=true;
    b[x,y]:=z;
    b[y,x]:=z;
  end;
  readln(p);
  for i:=1 to p do
   begin
     readln(x,y);
     if a[x,y]=false then d[i]:=-1
     else
     begin
       for k:=n downto 1do
       if a[k,y]and a[k,x] then
       if min(b[k,y],b[k,x])>b[x,y]then d[i]:=min(b[k,y],b[k,x])
       else d[i]:=b[x,y];
     end;
   end;
   for i:=1 to p do writeln(d[i]);
  close(input);close(output);
end.




