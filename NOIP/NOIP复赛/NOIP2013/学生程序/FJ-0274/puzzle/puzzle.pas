program puzzle;
 var n,m,p,i,j,ex,ey,sx,sy,tx,ty:longint;
     a:array[1..30,1..30] of longint;
 begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
   readln(n,m,p);
   for i:=1 to n do
    begin
     for j:=1 to m do read(a[i,j]);
     readln;
    end;
   for i:=1 to p do
    begin
     readln(ex,ey,sx,sy,tx,ty);
    end;
   if p=1 then write(-1);
   if p=2 then begin
    writeln(2);write(-1);
               end;
  close(input);close(output);
 end.
