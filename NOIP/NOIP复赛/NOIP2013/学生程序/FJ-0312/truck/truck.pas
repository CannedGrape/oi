program truck;
var i,j,n,m,k,p,q,x,y,z:longint;
    a:array[1..1000,1..1000]of longint;
begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    readln(x,y,z);
    if a[x,y]<z then begin a[x,y]:=z;a[y,x]:=z;end;
  end;
  for k:=1 to n do
  for i:=1 to n do
  for j:=1 to n do
  begin
    if a[i,k]>a[k,j]then p:=a[k,j]else p:=a[i,k];
    if p>a[i,j]then a[i,j]:=p;
  end;
  readln(q);
  for i:=1 to q do
  begin
    readln(x,y);
    if a[x,y]=0then write(-1)else write(a[x,y]);
    writeln;
  end;
end.