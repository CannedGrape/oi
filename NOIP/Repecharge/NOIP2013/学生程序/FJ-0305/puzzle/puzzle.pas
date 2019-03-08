var n,m,q,i,j:integer;a:array[1..30,1..30]of integer;
    ex,ey,sx,sy,tx,ty:array[1..501]of integer;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
rewrite(output);
   read(n,m,q);
   for i:=1 to n do begin readln;
    for j:=1 to m do read(a[n,m]);
     end;
   for i:=1 to q do readln(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);
   for i:=1 to q do writeln('-1');
   close(input);
   close(output);
end.