program number;
var n,p,i,j,max,s:longint;
    a,f,t:array[1..1000000] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    a[i]:=a[i] mod p;


  for i:=1 to n do
  begin
    for j:=i downto 1 do
    if t[i]>=0 then
      t[i]:=a[j]+t[i];
    if t[i]=0 then t[i]:=a[i];
  end;
  f[1]:=t[1];
  for i:=2 to n do
  begin
    f[i]:=t[i-1]+f[i-1];
    if f[i]>max then max:=f[i];
  end;
  if f[n]>=0 then
    if f[n] div p>=1 then
    for i:=1 to f[n] div p do
    begin
      s:=f[n] mod p;
      write(s);
    end
    else write(f[n])
  else write('-',abs(f[n] mod p));
  close(input);
  close(output);
end.
