var n,m,i,j:longint;
    a:array[0..1000,1..1000]of longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  for i:=1 to m do
    begin
      read(a[i,0]);
      for j:=1 to a[i,0] do read(a[i,j]);
      readln;
    end;
  writeln(m);
  close(input);close(output);
end.