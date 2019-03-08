program number;
var n,p,i:longint;
    max:int64;
    a:array[1..1000000]of longint;
    b:array[1..1000000]of int64;
    c:array[1..1000000]of int64;
begin
  assign(input,'number.in');
  reset(input);
  assign(output,'number.out');
  rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  readln;
  b[1]:=a[1];
  max:=a[1];
  for i:=2 to n do
  begin
    if a[i]>0 then max:=max+a[i];
    b[i]:=max;
  end;
  c[1]:=b[1];
  c[2]:=c[1]+b[1];
  max:=c[2];
  for i:=3 to n do
  begin
    if c[i-1]+b[i-1]>max then
    begin
      c[i]:=c[i-1]+b[i-1];
      max:=c[i-1]+b[i-1];
    end
    else c[i]:=max;
  end;
  if c[1]>max then max:=c[1];
  writeln(max mod p);
  close(input);
  close(output);
end.                 