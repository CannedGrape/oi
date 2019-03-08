program count;
var
  i,k,n,x:longint;
  a:array[1..1000000]of longint;
  s,z:ansistring;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  readln(n,x);
  s:=''; k:=0;
  for i:=1 to n do
  a[i]:=i;
  for i:=1 to n do
  begin
    str(a[i],z);
    s:=s+z;
  end;
  for i:=1 to length(s)do
  if ord(s[i])-48=x then inc(k);
  write(k);
  close(input);
  close(output);
end.

