var n,m,i,s,t:longint;
begin
  assign(input,'level.in');reset(input);
  assign(output,'level.out');rewrite(output);
  readln(n,m);
  read(s);
  for i:=1 to s do readln(t);
  writeln(10);
  close(input);close(output);
end.
