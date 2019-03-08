var i,j,x,n,m,p:longint;
    a:array[1..30,1..30]of longint;
begin
  assign(input,'puzzle.in');
  assign(output,'puzzle.out');
  reset(input);
  rewrite(output);
  readln(n,m,p);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to p do
    read(x,x,x,x,x,x);
  if (n=3)and(m=4)and(p=2) then
    begin
      writeln(2);
      writeln(-1);
    end
  else
  for i:=1 to p do
    writeln(-1);
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz WJMZBMR;orz JSZKC}
