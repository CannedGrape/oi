var
  s,t:ansistring;
  n,x,i,j,a:longint;
begin
  assign(input);
  reset(input,'count.in');
  assign(output);
  rewrite(output,'count.out');
  readln(n,x);
  a:=0;
  str(x,t);
  for i:=1 to n do
  begin
  str(i,s);
  for j:=1 to length(s) do
  if s[j]=t then a:=a+1;
  end;
  writeln(a);
  close(input);
  close(output);
  readln;readln;
end.
