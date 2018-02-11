program match;
var
  a,b:array[1..1000000] of longint;
  i,t,n:longint;

begin
  assign(input,'match.in');
  reset(input);
  assign(output,'match.out');
  rewrite(output);
  readln(n);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  t:=0;
  for i:= 1 to n do
    begin
    if (a[i]>b[i])and(a[i]>a[i+1])then
      inc(t);
      t:=t mod  99999997;
    end;
  for i:=1 to n do
    if (b[i]>a[i])and(b[i]>b[i+1]) then  begin
      inc(t);
      t:=t mod 99999997;
    end;

  writeln(t);
  close(input);
  close(output);
end.
