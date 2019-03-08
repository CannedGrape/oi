var
  i,j,m,n,x,k,l,s:longint;
  a:array[0..1000000] of longint;
begin
  assign(input,'circle.in'); reset(input);
  assign(output,'circle.out'); rewrite(output);
  readln(n,m,k,x);
  l:=10;
  for i:=1 to k-1 do
    l:=l*10;
  for i:=1 to n do
    begin
    a[i]:=a[i-1]+m;
    if a[i]>=n then a[i]:=a[i] mod n;
    end;
  s:=l mod n;
  writeln(a[s]+x);
  close(input); close(output);
end.
