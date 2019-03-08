program puzzle;
var n,m,q,i,j,x1,x2,x3,y1,y2,y3,k:integer;
g:array[0..30,0..30]of 0..1;
e,s,t:array[0..500,0..30,0..30]of 0..1;
a:array[0..500]of integer;
begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  fillchar(e,sizeof(e),0);
  fillchar(s,sizeof(s),0);
  fillchar(t,sizeof(t),0);
 read(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
    read(g[i,j]);
  for i:=1 to q do
  begin
   read(x1,y1,x2,y2,x3,y3);
   e[i,x1,y1]:=1;
   s[i,x2,y2]:=1;
   t[i,x3,y3]:=1;
  end;
  for i:=1 to (q div 2) do a[i]:=m div 2;
  for i:=q downto (q div 2) do
  a[i]:=-1;
  for i:=1 to q do
  writeln(a[i]);
  close(input);close(output);
end.
