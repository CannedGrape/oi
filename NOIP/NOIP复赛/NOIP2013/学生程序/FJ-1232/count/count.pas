program exam1;
var  s,s1:ansistring;
    j,i,n,x,y,ans:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  rewrite(output);
  read(n,x);
  str(x,s1);
  ans:=0;
  for i:=1 to n do
  begin
  str(i,s);
  j:=pos(s1,s);
  while j<>0 do
  begin
  inc(ans);
  delete(s,1,j);
  j:=pos(s1,s);
  end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.

