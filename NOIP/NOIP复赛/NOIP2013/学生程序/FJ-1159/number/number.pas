var a,b,c,e,i,j,k,max,n:longint;
    x,y,z,x2:array[1..1000000] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  read(a,b);
  for i:=1 to a do
  begin
    read(z[i]);
    {x[i]:=0;}
  end;
  x[1]:=z[1];
  for i:=2 to a do
  for j:=1 to i do
  begin
    if (z[j]>=0) then x[i]:=x[i]+z[j] else
    begin if (x[i]<z[j]) then x[i]:=z[j];end;
  end;
  y[1]:=x[1];
  if 2*y[1]>0 then max:=2*x[1] else max:=y[1];
  for i:=2 to a do
  begin
    y[i]:=max;
    if (x[i]+y[i]>max) and (i<>a)then max:=x[i]+y[i];
  end;
  writeln(max mod b);
  close(input);
  close(output);
end.
