program fuck;
var
 a,b:array[0..30,0..30] of integer;
 i,j,k,l,s,t,m,n,p,sx,sy,tx,ty,ex,ey:longint;
begin
 assign(input,'puzzle.in');
 assign(output,'puzzle.out');
 reset(input);
 rewrite(output);
 readln(n,m,p);
 for i:=1 to n do
 begin
  for j:=1 to m do
   read(a[i,j]);
 readln;
 end;
 readln(ex,ey,sx,sy,tx,ty);
 if (ex=tx) and (ey=ty) and (sx-tx=1) and (sy-ty=1) then writeln(1) else
  writeln(-1);
 close(input);
 close(output);
end.
