var a,b:array[1..50000]of longint;
    c:array[1..100000]of longint;
    x,y,t:array[1..30000]of longint;
    i,n,m,q,v,u:longint;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
  readln(n,m);
  for i:=1 to m do readln(a[i],b[i],c[i]);
  readln(q);
  for i:=1 to q do readln(x[i],y[i]);
  for i:=1 to m do
   for j:=1 to q do
    if b[i]<y[j] then t[q]:=-1;
  for i:=1 to m do
   for j:=1 to q do
    if a[i]=x[j] then begin I1:=i
     for u:=1 to m do
      for v:=1 to q do
       if b[i]=y[j] then begin  u1:=i
     then begin
      if c[I1]>c[u1] then t[q]:=c[u1];
      if c[I1]<=c[u1] then t[q]:=c[I1];
   for i:=1 to q do writeln(t[q]);
close(input);
close(output);
end.
