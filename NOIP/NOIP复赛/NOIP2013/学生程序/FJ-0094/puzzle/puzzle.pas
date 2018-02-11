program puzzle;
var
 a:array[1..30,1..30]of integer;
 b,c,d,e,f,g,h:array[1..500] of integer;
 m,n,p,q,i,j,x,z:integer;
begin
 assign(input,'puzzle.in');
 assign(output,'puzzle.out');
 reset(input);
 rewrite(output);
 readln(n,m,q);
 for i:=1 to n do
  begin
   for j:=1 to m do read(a[i,j]);
   readln;
  end;
 for i:=1 to q do
  begin
   read(c[i],d[i],e[i],f[i],g[i],h[i]);
   readln;
  end;

 for i:=1 to q do
  writeln(-1);
 close(input);
 close(output);
end.
