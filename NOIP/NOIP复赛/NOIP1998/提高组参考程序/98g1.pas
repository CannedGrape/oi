var
  f:array[1..23] of integer;
  i,a,n,m,x:integer;
begin
  f[1]:=1; f[2]:=1;
  for i:=3 to 23 do f[i]:=f[i-1]+f[i-2];
  write('a,n,m,x=');
  readln(a,n,m,x);
  writeln((f[x-2]+1)*a+(f[x-1]-1)*(m-(f[n-3]+1)*a) div (f[n-2]-1));
end.
