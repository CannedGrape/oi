var
  x,i,a,m,l:longint;
begin
  assign(input,'count.in');reset(input);
  assign(output,'count.out'); rewrite(output);
  readln(a,x);
  for i:=1 to a do
  if (i mod 10=x) or (i div 10=x)  then
  inc(m);
  writeln(m);
  close(input);close(output);
  readln;
end.