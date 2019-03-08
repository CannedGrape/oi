var
  n,m,i,j,k,sm:longint;
  s:array[0..1001]of longint;
  a,b:array[0..1001,0..1001]of longint;
begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(s[i]);
      for j:=1 to s[i] do
        read(a[i,j]);
      b[i,a[i,j]]:=1;
    end;
  sm:=2;
  for i:=2 to m do
    for j:=2 to n-1 do
      begin
        if b[i,j]<>b[i-1,j] then inc(sm);
      end;
  writeln(sm);
  close(input);
  close(output);
end.
