var
  max,i,n,p:longint;
  a:array[1..1000000]of longint;
  b:array[1..1000000]of longint;
  procedure who(i:longint);
  var j:longint;
  begin
    for j:=1 to i-1 do
      if a[j]>=0 then a[i]:=a[i]+a[j];
  end;
  procedure whose(i:longint);
  var mx,j:longint;
  begin
    mx:=-2000000000;
    for j:=1 to i-1 do
      if a[j]+b[j]>max then max:=a[j]+b[j];
    b[i]:=max;
  end;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
  max:=-2000000000;
  readln(n,p);
  for i:=1 to n do
    read(a[i]);
  readln;
  for i:=n downto 2 do
    who(i);
  b[1]:=a[1];
  for i:=2 to n do
    whose(i);
  for i:=1 to n do
    if b[i]>max then max:=b[i];
  writeln(max mod p);
  close(input);
  close(output);
end.