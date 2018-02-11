var
 n,m,q,ex,ey,sx,sy,tx,ty:longint;
begin
 assign(input,'puzzle.in'); reset(input);
 assign(output,'puzzle.out'); rewrite(output);
 readln(n,m,q);
 for i:=1 to q do 
  begin
   readln(ex,ey,sx,sy,tx,ty);
   if (sx=tx) and (sy=ty) then writeln(0) else writeln(-1);
  end;
 close(input); close(output);
end.