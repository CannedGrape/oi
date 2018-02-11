program truck;
var n,i,j,m,q,z,x,y,k:longint;
a,b,c,max:array[1..30000]of longint;
h,t:array[1..30000]of integer;
begin
assign(input,'truck.in');
reset(input);
assign(output,'truck.out');
rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
    read(x,y,z);
    a[i]:=x;b[i]:=y;c[i]:=z;
    end;
  readln(q);
  for i:=1 to q do
    begin
    read(x,y);
    h[i]:=x;t[i]:=y;max[i]:=-1;
    end;
      i:=1;j:=1;k:=1;

    while (a[i]<>h[j])and(i<m) do inc(i);
    if i<m then if b[i]=t[j] then max[j]:=c[i] else
     begin
     while (a[k]<>b[i])and(i<m) do inc(k);
     if k<m then if (b[k]=t[j])and(c[k]<c[i])then max[j]:=c[k] else
      max[j]:=c[i];
     end;
        for i:=1 to q do
    for j:=2 to q do
    if (h[i]=h[j])and(t[i]=t[j])then max[j]:=max[i];
  for i:=1 to q do
  writeln(max[i]);
close(input);close(output);
end.
