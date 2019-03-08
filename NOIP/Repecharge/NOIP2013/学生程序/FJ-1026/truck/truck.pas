var
  n,m,q,i,max,j:longint;
  x,y,z,c,d:array[1..10000] of longint;
  pass:array[1..10000] of boolean;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  max:=-maxlongint;
  fillchar(pass,sizeof(pass),true);
  for i:=1 to m do
  read(x[i],y[i],z[i]);
  readln(q);
  for i:=1 to q do
  read(c[i],d[i]);
  if (x[i]<>y[i]) and (c[i]<>d[i]) then pass[i]:=true;
  if pass[i] then
  begin
  for i:=1 to n do
  begin
    for j:=1 to n do
    if (z[i]<z[j]) and (z[i]>max) then write(z[i])
     else if (z[j]>max) then write(z[j]);
  end;
  if pass[i]=false then
    writeln('-1');
  end;
  close(input);close(output);
end.
