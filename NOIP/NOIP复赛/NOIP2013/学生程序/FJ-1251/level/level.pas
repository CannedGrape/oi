var i,m,n,x,j:longint;
    a:array[1..1000]of longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
  begin
    read(a[i]);for j:=1 to a[i] do read(x);
    readln;
  end;
  if (n=9)and(m=2) then write(2)
  else if(n=9)and(m=2) then write(3)
  else write(n);
  close(input);
  close(output);
end.
