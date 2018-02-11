program Project1;
var n,p,i,max:longint;
    a,b,c:array[1..1000000] of longint;
begin
  assign(input,'number.in');  assign(output,'number.out');
  reset(input);rewrite(output);
  readln(n,p);
  for i:=1 to n do read(a[i]);
  b[1]:=a[1];   c[1]:=b[1];  max:=0;
  for i:=2 to n do
    b[i]:=a[i]+b[i-1];
  for i:=2 to n do
    c[i]:=c[i-1]+b[i-1];
  for i:=1 to n do
    if c[i]>max then max:=c[i];
  max:=max mod p;
  writeln(max);
  close(input);close(output);
end.
