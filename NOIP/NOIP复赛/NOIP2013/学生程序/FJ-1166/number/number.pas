program number;
var
  z,t,f:array[0..1000001] of longint;
  n,i,j,k,p,x,y,c:longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  k:=0;
  for i:=1 to n do
    read(z[i]);
  t[1]:=z[1];
  f[1]:=z[1];
  for i:=2 to n do
  begin
    for x:=1 to i do
    for y:=1 to i do
    begin
      if x<y then
      for j:=x to y do
        c:=c+z[j]
        else
        for j:=y to x do
        c:=c+z[j];
      if t[i]<c then t[i]:=c;
    end;
  end;
  for i:=1 to n do
  begin
    for j:=1 to i-1 do
    inc(f[i],f[j]);
    f[i]:=f[i]+t[i];
  end;
  for i:=1 to n do
  if f[i]>k then k:=f[i];
  writeln(abs(k) mod p);
  close(input);
  close(output);
end.
