var
  m,n,k,x,t,i:longint;
  a:array[1..10000] of longint;
begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);
  for i:=1 to 10 do
  begin
    while t<=i*k do
    begin
      a[x]:=a[x+m];
      inc(t);
    end;
  end;
  writeln(x);
  readln;
  close(input);close(output);
end.
