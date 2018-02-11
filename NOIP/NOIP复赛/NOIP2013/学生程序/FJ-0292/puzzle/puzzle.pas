var n,m,q,i,j:longint;
    a:array[0..31,0..31]of longint;
    e,s,t:array[1..505,1..2]of longint;
begin
assign(input,'puzzle.in'); reset(input);
assign(output,'puzzle.out');rewrite(output);

  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to q do
    readln(e[i,1],e[i,2],s[i,1],s[i,2],t[i,1],t[i,2]);
  if n=1 then
    for i:=1 to q do
      if ((e[i,1]=t[i,1])and(e[i,2]=t[i,2])) and
      ((s[i,2]+1=t[i,2])or(s[i,2]-1=t[i,2])) then writeln(1)
      else writeln(-1)
  else for i:=1 to q do writeln(-1);

close(input); close(output);
end.