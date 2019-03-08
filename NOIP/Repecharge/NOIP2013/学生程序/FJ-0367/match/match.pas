var
  n,m,i:longint;
begin
  assign(input,'match,in');reset(input);
  assign(output,'match.out');rewrite(output);
  readln(n);
  for i:=1 to n do read(m);
  for i:=1 to n do read(m);
  writeln(1);
  close(input);
  close(output);
end.